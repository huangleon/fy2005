inherit ROOM;

void create()
{
	set("short", "������ɽ·");

	set("long", @LONG
һ���ӿ����ݵ�ʯ��ɽ·�����Թ�ʯ��ᾡ������ɽ����ʱ��ʱ���������Ǻ�
����·���������Լ������װ׹ǡ�͸��ɽ����Լ��ɿ������Ϸ���Զ����һ��
������
LONG);
	set("type","road");
	set("exits",([
		"northdown":__DIR__"ehugang",
		"southup":__DIR__"shanlu4",
		"southwest":__DIR__"undertower",
	]) );

	set("outdoors", "bawang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);

	setup();

}


int valid_leave(object me, string dir)
{
	if(dir == "southup"){ 	
     	REWARD_D->riddle_done(me,"̽������",10,1);
     	if (QUESTS_D->verify_quest(me,"̽������"))
			QUESTS_D->special_reward(me,"̽������");
	}
	return 1;
}

