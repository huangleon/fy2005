inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ����������ò��������Ƕ������ϱ��̵��Ľ���֮����·����д�ţ�
    [33m��������ɽ��  ����ǧ��ɽ��  �ϡ����Ƴǡ�  ��������֮��[32m
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road1",
  "east" : AREA_JINAN"road1q",
 "westup" : AREA_DAOGUAN"sroad",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",-10040);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
