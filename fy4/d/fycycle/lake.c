inherit ROOM;
void create()
{
        set("short", "÷��");
        set("long", @LONG
����ת�˼����䣬��ض���÷�����ϸɺ�б��֦Ҷï�ܣ��������÷��ʢ��֮
�գ���ѩ�纣����Ȼ���Ͳ������в�������ת����һ��ɽ���µ�С�����ߵ�һ��
С��ǰ��÷�����У�������ʯ�ݣ��컨���ݣ���������ͼ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"northeast" : __DIR__"sroad3",
  		"west":      __DIR__"village",
	]));
        set("outdoors", "fengyun");
		set("coor/x",-120);
		set("coor/y",-320);
		set("coor/z",0);
        setup();
}

int valid_leave(object who, string dir) {
	object ob;
	
	if (dir == "west") {
		if (QUESTS_D->verify_quest(who,"����ҽ��"))
		QUESTS_D->special_reward(who,"����ҽ��");
	}			
	return ::valid_leave(who, dir);	
}

