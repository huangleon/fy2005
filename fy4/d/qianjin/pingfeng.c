inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
���������Ͽ񾢲��飺
�ﻪ��̩��������������ѿ����̣����������ࡣһ���һ�����񣬰�Ϫ��ˮ
��������������꣬�������顣��ɹ�����ޣ�����̦���ᡣɽɫ��ά��Ũ��������
�������ݺᡣ�������������ͣ�������ȴ���顣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : AREA_FY"qianjin",
  		"west" : __DIR__"garden",
	]));
        set("objects", ([
        __DIR__"npc/laohan": 1,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
