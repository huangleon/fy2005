
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ�����
���������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlong",
		"north" : __DIR__"jlonglang2",
        ]));
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
}


