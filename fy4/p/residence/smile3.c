

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

如果你是一个“平凡”的人，那一定过得很幸福快乐了。
平凡，自开天以来，上苍就赐予了我们这个权利，可是，我们却疏忽它，不要它。

LONG);
        set("exits", ([
"307" : __DIR__"userroom/pinger1396667521",
"306" : __DIR__"userroom/hua1396581947",
"305" : __DIR__"userroom/thunder1396506761",
"304" : __DIR__"userroom/elec1396448442",
"303" : __DIR__"userroom/misty1396405304",
"302" : __DIR__"userroom/windy1396345620",
"301" : __DIR__"userroom/budd1396341416",
  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
