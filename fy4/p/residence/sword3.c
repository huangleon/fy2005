

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

一个人就算久已习惯了孤独和寂寞，但有时还是会觉得很难忍受，
他忽然希望能有个人陪在他身边，不管什么样的人都好，越粗俗无知的人越好，
因为这种人不能接触到他内心深处的痛苦。

LONG);
        set("exits", ([

  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
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
