
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ���,
������������ض��ǣ�͸������ˮ������Կ���������������޳��Ĵ��ȣ���ͦ��
���ţ����ںڵĳ���������������
LONG
        );
        set("exits", ([
                "south" : __DIR__"hfenglang1",
		"east" : __DIR__"hfenglang3",
        ]));
        set("coor/x",21);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
