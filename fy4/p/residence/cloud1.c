

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "�����ײ�");
  set ("long", @LONG

��������������ǰ�����裬�����þ���
�����������ŵ����ҷ׷�
����������������ˮ�����ί������

������������ǧ˿�ղ��ģ�����������
���������ػ���Ц���޸�
���������÷�Ƶ���������������ơ�

LONG);
        set("exits", ([
"101" : __DIR__"userroom/mhu1395941612",
//  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
  "north" : __DIR__"enterance", 
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
