

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "非天塔"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

朋友就是朋友，朋友绝不分好坏，因为朋友只有一种。
如果你对不起我，出卖了我，你根本就不是我的朋友，根本就不配说这两个字。

LONG);
        set("exits", ([
  "down" : __DIR__"tower1",
  "up" : __DIR__"tower3", 
]));
  	set("coor/x",-10);
	set("coor/y",-40);
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
