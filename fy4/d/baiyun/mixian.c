//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
�Ź����꣬������ߣ���ѧ���衣ϯ����ǰ�����������������С���һЦ��
��ǧ������ֻ�֡�����˲��͵����������ȡ�
    ���ܾ����ˡ����뻨Ϊ�������ﵤ�����η�Я��ͬ��ȥ������ȴ���̻����¡�
���˼�檣�����ĺ�ꡣ 
LONG
    );
    set("exits",
      ([
	"down" : __DIR__"yaoxian",
	"up" : __DIR__"yinxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/mixian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",50);
    setup();
    replace_program(ROOM);
}
