

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "�ؽ��󶥲�");
  set ("long", @LONG

�����������������������������佭����׷�

����������������������������

LONG);
        set("exits", ([
  "down" : __DIR__"sword"+(query("floor")-1),
]));
  	set("coor/x",-30);
	set("coor/y",-40);
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
