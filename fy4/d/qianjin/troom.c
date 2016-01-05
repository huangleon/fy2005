inherit ROOM;
void create()
{
        set("short", "˽�̷�");
        set("long", @LONG
������ǧ��¥����Ϊ潵ĵط���ÿ�����Ͼͷ��Ĺ��ﶼ�ᱻ�������������
�ȡ��绹���ӣ������̿���ǽ�Ϻ͵��϶��а���ɫ��Ѫ�����ݽ�һ�Ű����С����
���Ϸ��ҵĴ������ƺ���������ҧ���ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 	 		"west" : __DIR__"sr2",
	]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
                        ]) );

	set("coor/x",-50);
	set("coor/y",15);
	set("coor/z",-10);
	setup();

}
			
void reset() {
	string item= "broken_cloth";
	int num = 2;
	object obj, *inv;
	
	:: reset();
	
	inv = all_inventory();
	foreach (object ob in inv) 
	{
		if (userp(ob)) continue;
		if (ob->query("id") == "neiyi") destruct(ob);
	}
	while (num--) 
	{
		obj = new(__DIR__"obj/"+item);
		obj->move(this_object());
	}
}

int valid_leave(object me, string dir)
{
 	REWARD_D->riddle_done(me,"ǧ�𰵲�",10,1);
	if (QUESTS_D->verify_quest(me,"ǧ�𰵲�"))
		QUESTS_D->special_reward(me,"ǧ�𰵲�");  
	return 1;
}