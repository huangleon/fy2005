
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����еƻ�ͨ����������磬������ʵ��һ�����á����еĳ������������
�ƹ���ҫ�¸��ǻ������ϱ�������ȫ����֦�����Σ����а�����ʯ���ӡ���ʯ���ӡ�
���濿ǽ��һ����ľ���ӣ���������ű�����觡�ɺ������ʯ�������������в�
�ŷ�������̫ʦ�Σ�������һ�����磬��ס�˶�����ձڡ�
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"village1",
		"south": __DIR__"lroad3",
		"east": __DIR__"pingfeng",
	]));
        set("item_desc", ([
			"��ľ����":	"��ľ���ӣ���������ű�����觡�ɺ������ʯ����������\n",
			"����":		"һ�Ⱥܴ��������ס�˺���Ķ�����\n",
			"�ձ�":		"һ�Ⱥܴ��������ס�˺���Ķ�����\n",
	 ]));
	 set("objects", ([
        	__DIR__"npc/daniang": 1,
        	__DIR__"npc/whitewoman2": 2,
    	]) );
	set("coor/x",70);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

int valid_leave(object me,string dir) {

	object li,woman;
	li=present("li daniang",this_object());
	if (dir=="east" && li)
	if (!userp(li)) {
		message_vision(li->name()+"����һ�Σ���ס��$N��ȥ·��\n",me);
		return notify_fail("");
	}
	woman=present("white cloth woman",this_object());
	if (dir=="east" && woman)
	if (!userp(woman)) {
		message_vision(woman->name()+"����һ�Σ���ס��$N��ȥ·��\n",me);
		return notify_fail("");
	}
	return 1;
	
}