#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�⹳˪ѩ");
	set("long", @LONG
�����ıڼ�������ý�׵ĺ�������������Ŀ��˪��ѩ���ı��Ͼ�Ȼ������
���ָ����ĵ����÷絶����β�����������е����󻷵����Լ����в������ֵ�
����������עĿ��ȴ�ǰ����������е�һ������İ���ʯ�������侲���ذ�����
�ȴ������Ө�Ĺ�ʺ�Ī���Ķ���֮����
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/bladebook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

