
inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�������Ե��Ӳݣ��㾪�ȵط��ֺ��澹Ȼ�����߹��ļ��󣬵��߸ߴ�����Ĺ�
ľ���γ�����Ȼ�����ϣ��ټ��ϵ��ƽ��ͣ�û��ע�⵽���ﾹ����·�������˿���
�µ���·����ͨ��η���ǰ���Ȼ����һ��ɽ����
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"smallroad4",
  		"west" : __DIR__"cave_tunnel",
	]));
        set("outdoors", "resort");
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

