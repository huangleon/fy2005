
inherit ROOM;

void create()
{
        set("short", "����ǰ��");
        set("long", @LONG
�ذ����Ϻõ�̴��ľ���⻬���Դ���ʪ�����ֱ���һ����̨�������и�����,
��������˰�ë�������绨�����СѾ������æµ�������⣬һ���޴����
ͭ�׼����һ��ϣ�Ѿ�������������ļ�����Ȫˮ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind3",
		"west" : __DIR__"jlonglang1",
        ]));
        set("objects", ([
                __DIR__"npc/": 2,
        ]) );
        set("coor/x",-10);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
}
