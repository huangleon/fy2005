

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "�ؽ���ײ�");
  set ("long", @LONG

�����������������¥�ϣ���������ʡ�
��������׳����������У������Ƶͣ���������硣
����������������ɮ®�£���������Ҳ��
��������������������飬һ�ν�ǰ��ε�������

LONG);
        set("exits", ([
"102" : __DIR__"userroom/isan1396011428",
"101" : __DIR__"userroom/kana1395838262",//  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
  "east" : __DIR__"enterance", 
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
