class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        int n = routes.length;

        HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();

        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].length;j++){
                int bustopno = routes[i][j];
                ArrayList<Integer> busno = map.getOrDefault(bustopno,new ArrayList<>());
                busno.add(i);
                map.put(bustopno,busno);
            }
        }

        LinkedList<Integer> queue = new LinkedList<>();
        HashSet<Integer> busstopvis = new HashSet<> ();
        HashSet<Integer> busvis = new HashSet<> ();
        int level = 0;

        queue.addLast(S);
        busstopvis.add(S);
        while(queue.size()>0){
            int size = queue.size();
            while(size-->0){
                int rem = queue.removeFirst();

                if(rem == T){
                    return level;
                }

                ArrayList<Integer> buses = map.get(rem);
                for(int bus: buses){
                    if(busvis.contains(bus)==true){
                        continue;
                    }
                    int[]arr = routes[bus];
                    for(int busstop : arr){
                        if(busstopvis.contains(busstop)==true){
                            continue;
                        }
                        
                        queue.addLast(busstop);
                        busstopvis.add(busstop);
                    }
                    busvis.add(bus);
                }
            }
            level++;
        }

        return -1;
    }
}