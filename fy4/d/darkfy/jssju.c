
inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�˼�����Ƿ��Ƴ���������࣬���ĵط���������ϰ������������˵�ǵ����
̫�ӵ���ʦ�����Ǿ����������飬���������͵����Ȼ��̰�ӡˢ�����ﲻ���ܶ��
ɧ����ϲ����ʫ�ʣ�����һЩ��ǳ�Ĺ����飬�����о�������ǿ���塣
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind1",
        ]));
        set("objects", ([
                __DIR__"npc/": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
