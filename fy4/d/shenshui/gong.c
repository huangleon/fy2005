// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
һ���ߴ�ĵ��ã���ɽ��������˽�����ʵ������̾Ϊ��ֹ���ɼ���˼�˵���
���Ƕ�ô����������Ƕ���ľ޴󡣵�ܴ��м�ȴû��һ�����ӣ����Ķ���
�����˸�ɫ�����ɺ�������м���һ�ŵ��Σ����ܾ�����վ�˼�����Ů��
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ 
  "southdown" : __DIR__"huoyan",
  "east" : __DIR__"shanfang",
  "west" : __DIR__"yaofang",
  "northeast" : __DIR__"woshi",
  "northwest" : __DIR__"qingong",
   ]));
   
   set("objects", ([
      __DIR__"npc/master" : 1,
      __DIR__"npc/girl": 3,
   ]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}


int valid_leave(object me, string dir)
{

 	REWARD_D->riddle_done(me,"��ˮ̽��",10,1);
	
/*	if (me->query("marks/enter_ss/����") 
		&& me->query("marks/enter_ss/��ʯ") 
		&& me->query("marks/enter_ss/����")) {
		me->delete("marks/enter_ss");
		REWARD_D->riddle_done(me,"������ˮ",20,1);
	}*/
	
	if (QUESTS_D->verify_quest(me,"��ˮ̽��"))
		QUESTS_D->special_reward(me,"��ˮ̽��");
	return 1;		
	
}

