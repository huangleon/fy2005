

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "������");
  set ("long", @LONG

�������������ϰ��񾩡�ʮ��¥��ǡ����˸��Ҷ����ᷢ�ܳ���

������������ʮ��ʥ�������ƹҿ�������ض�һ����δ����ս����

LONG);
        set("exits", ([
  "down" : __DIR__"cloud"+(query("floor")-1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
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
