

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "Цǳ¥"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

�����������������������߹���Ҷ
��������������������������
������������Ӧ��������
������������������������������Ѱ��

LONG);
        set("exits", ([
//  "down" : __DIR__"valley"+(query("floor")-1),
  "up" : __DIR__"valley"+(query("floor")+1), 
  "south" : __DIR__"enterance", 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
