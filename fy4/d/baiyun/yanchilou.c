//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���¥");
    set("long", @LONG
���¥�����ˣ�������һ�����ܼⶥ���Iͤ������¥�ϵĹ��Σ����滷�������
ͻ�����ߵʹ��䣬�������ศ��������ΰ���С����¥��֮�ơ�¥�Ϲ�׭һ����
                           ��    �� 
                           ��    ��
                           ӭ    ��
                           ��    ��
LONG
    );
    set("exits",
      ([
	"northdown" : __DIR__"dragonplace",
	"southeast" : __DIR__"emaze8",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	__DIR__"npc/songshi" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-30);
    set("coor/y",-70);
    set("coor/z",20);
    setup();
    replace_program(ROOM);
}
