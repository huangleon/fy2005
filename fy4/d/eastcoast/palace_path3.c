
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
	  "eastup" : __DIR__"palace_path4",
  	  "westdown" : __DIR__"palace_path2",
	]));
        set("outdoors", "palace");

	set("coor/x",120);
	set("coor/y",0);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

