class FoodRatings {
public:
    map<string, int> foodToRating;
    map<string, set<pair<int, string>>> cuisineToFoodAndRating;
    map<string, string> foodToCuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();

        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToRating[food] = rating;
            cuisineToFoodAndRating[cuisine].insert({-rating, food});
            foodToCuisine[food] = cuisine;
        }
    }

    void changeRating(string food, int newRating) {
        int oldRating = foodToRating[food];
        string cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        cuisineToFoodAndRating[cuisine].erase({-oldRating, food});
        cuisineToFoodAndRating[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return begin(cuisineToFoodAndRating[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */