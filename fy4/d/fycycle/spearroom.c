#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�������");
	set("long", @LONG
�߽��˼䣬ɭɭ���������������ɫ��ǽ���±ߣ��޹������Ƕ�Ű�ɫ�ĳ�
ʯ����ͬ���������ѵĸ��������п���һ�ȴ������ɱ�����ı�ӿ������վ��
��������۲죬���������ı���ɱ��͸�ڶ������ƺ��м�����ʮ��ױ���
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/spearbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

