// File: object_placement_astar.cpp
// Purpose: Arrange 5 rectangles + 4 squares in a ROOM_W×ROOM_H grid via A*.

#include <bits/stdc++.h>
using namespace std;

struct Obj { int w,h; string name; };

struct Node {
    vector<bool> used;
    vector<pair<int,int>> pos;
    int g,h;
    bool operator<(const Node &o) const {
        return (g+h) > (o.g+o.h);
    }
};

int ROOM_W = 10, ROOM_H = 8;
vector<Obj> objects;

int heuristic(const Node &n){
    int areaUsed=0;
    for(int i=0;i<objects.size();i++)
        if(n.used[i]) areaUsed += objects[i].w*objects[i].h;
    return ROOM_W*ROOM_H - areaUsed;
}

bool canPlace(const Node &n,int idx,int x,int y){
    auto &o=objects[idx];
    if(x+o.w>ROOM_W||y+o.h>ROOM_H) return false;
    for(int j=0;j<objects.size();j++) if(n.used[j]){
        auto &o2=objects[j];
        auto [px,py]=n.pos[j];
        if(!(x+o.w <= px || px+o2.w <= x ||
             y+o.h <= py || py+o2.h <= y)) return false;
    }
    return true;
}

void solve(){
    objects = {
        {3,2,"Rect1"},{4,2,"Rect2"},{2,3,"Rect3"},
        {3,3,"Rect4"},{5,1,"Rect5"},
        {2,2,"Square1"},{2,2,"Square2"},
        {3,3,"Square3"},{1,1,"Square4"}
    };
    Node start;
    start.used.assign(objects.size(),false);
    start.pos.assign(objects.size(),{-1,-1});
    start.g=0; start.h=heuristic(start);

    priority_queue<Node> pq;
    pq.push(start);

    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        if(cur.h==0){
            cout<<"Arrangement found:\n";
            for(int i=0;i<objects.size();i++){
                cout<<objects[i].name
                    <<" @ ("<<cur.pos[i].first
                    <<","<<cur.pos[i].second<<")\n";
            }
            return;
        }
        for(int i=0;i<objects.size();i++) if(!cur.used[i]){
            for(int x=0;x<=ROOM_W-objects[i].w;x++){
                for(int y=0;y<=ROOM_H-objects[i].h;y++){
                    if(canPlace(cur,i,x,y)){
                        Node nxt = cur;
                        nxt.used[i]=true;
                        nxt.pos[i]={x,y};
                        nxt.g = cur.g+1;
                        nxt.h = heuristic(nxt);
                        pq.push(nxt);
                    }
                }
            }
        }
    }
    cout<<"No valid arrangement.\n";
}

int main(){
    cout<<"--- A* Object Placement ---\n";
    solve();
    return 0;
}
