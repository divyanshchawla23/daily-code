/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int util(MountainArray &arr){
        int n = arr.length();
        int l = 1;
        int r = n-2;

        while(l<=r){

            int mid = (l+r)/2;
            int midVal = arr.get(mid);


            if(midVal>arr.get(mid-1) && midVal>arr.get(mid+1)){
                return mid;
            }
            else if(midVal>arr.get(mid-1)){
                l = mid+1;
            }
            else if(midVal>arr.get(mid+1)){
                r = mid-1;
            }
        }

        return -1;
    }

    int bs(MountainArray &arr,int l, int r, int target){
        while(l<=r){

            int mid = (l+r)/2;
            int midVal = arr.get(mid);

            if(midVal==target){
                return mid;
            }

            else if(midVal<target){
                l = mid+1;
            }

            else r = mid-1;
        }
        return -1;
    }

    int rbs(MountainArray &arr,int l, int r, int target){
        while(l<=r){

            int mid = (l+r)/2;
            int midVal = arr.get(mid);

            if(midVal==target){
                return mid;
            }

            else if(midVal>target){
                l = mid+1;
            }

            else r = mid-1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int mountainIndex = util(mountainArr);

        int index = bs(mountainArr,0,mountainIndex,target);
        if(index!=-1){
            return index;
        }
        index = rbs(mountainArr,mountainIndex+1,n-1,target);

        return index;
    }
};