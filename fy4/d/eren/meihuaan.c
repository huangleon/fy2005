inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "÷������");
        set("long", @LONG
��ɫ�ݻƣ�Ϧ������Ҳ�����������Ѱ���Ĵ����ϡ���ϡ�����Էֱ����[35m÷
����[32m�������֡��������������÷���أ��ѵ���Щ��ǿ��÷�����ھ���һ���Ҿ���
徵�Ѫս�����ڷ���������ĲпᣬҲ�Ѿ����˼��޿���������Ը��ȥ�����գ�
��Ը�ڻ����л�Ϊ�ҽ���������Σ����������ڣ��������Ӣ���ǣ�ȴ�Ѻ�÷��һ
��ȫ�������˳�����
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"road2b",
		"enter": __DIR__"meihuaan2",
	]));
        set("objects", ([
		__DIR__"npc/m_nun" : 1,
	]) );
	set("coor/x",0);
        set("coor/y",20);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
