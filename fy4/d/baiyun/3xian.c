//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���ɱ�");
    set("long", @LONG
���Ƶ���Ϊ��������֮�أ����а���һ�ƣ�������ɮ����������������ʮ�أ�̤
����ԭѰ��ҩ�ݣ������˶��Σ�������Ҳ�Ⱥ�ʻ���Ϊ�˼������ˣ����Ƴ����Ľ���
��һ��ʯ�������飺���ɾۡ����������ڴ˴����̨��ˮȪ�����ܷ�������������
��Ƣ�������ڵ���Ҳ��ϲ�ڴ�С����
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"skystreet",
	"west" : __DIR__"skystreet3",
	"east" : __DIR__"skystreet4",
	"south" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([
	__DIR__"npc/byyouke" : 3,
      ]));
    set("resource/water",1);
    set("liquid",([
	"name":"����Ȫˮ",
	"container":"����Ȫ"]));

    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
