
inherit ROOM;

void create()
{
        set("short", "������Դ");
        set("long", @LONG
΢����������ף����������㡣������ɽ��������ɫ���ˡ�������Ǵ���
ɽ����������ǡ�˲���ɽ��Ѱ��һ�����Ҳ�������ҵ�������������������
������֮�У����ƺ��߳���������ǣ�ң�������������Դ��
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"small_river",
  		"east" : __DIR__"cave_tunnel",
	]));
        set("outdoors", "resort");

	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

