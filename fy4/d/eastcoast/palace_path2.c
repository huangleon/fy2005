
inherit ROOM;

void create()
{
        set("short", "��ã����·");
        set("long", @LONG
ɽ�������･�����ߣ�����Խ��ԽŨ����Χ�ľ�����Ũ�����������֡�Ũ��
�е�ˮ����͸��������ѣ������Ҳ�񱻱����������Χ�ˡ��⡭������ͨ������
�ļ���֮;������ͨ�������Ĳ���֮·��
LONG
        );
        set("exits", ([ 
  		"eastup" : __DIR__"palace_path3",
  		"west" : __DIR__"palace_path1",
]));
        set("outdoors", "palace");

	set("coor/x",110);
	set("coor/y",0);
	set("coor/z",0);

	setup();
}


