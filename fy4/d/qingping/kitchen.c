// XXder@fy3
inherit ROOM;
void create()
{
        set("short", "�﷿");
        set("long", @LONG
���������йɴ�е������������������Ѿ������æµ�ţ�̨���Ϻ�����̰�
��ʮ�������ӣ���Ϊ�ش�³�ϣ���ɫ���˿׸��˵�Ӱ�죬����Ҳ�ľ��¡�̨���ϵ�
���Ӽ��������޷�Ƭ��������������ߣ���û�뵽�����ﻹ�����������ص��Ĵ��ˡ�
������ʳ���Ǵ��պ���ͱ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"southting",
]));

	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
