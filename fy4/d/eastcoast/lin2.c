inherit ROOM;
void create()
{
	set("short", "�����Ŀյ�");
	set("long",@LONG
�յأ���ʯ���Ӳݣ����硣����ζ�����ˣ����˾��������ƺ��������Σ��ֿ�
��ɬ�������쳣�谵�������Լ���Ӱ�Ӷ�������������Ӳ�������ĹĶ���ɳɳ
��Ť����ͣ��Զ����Լ�������λ�����������
LONG);
	set("exits", ([
			"west" : __DIR__"lin1",
			"east" : __DIR__"fchuan",
	]) );
	set("objects", ([
			AREA_BAT"npc/wei": 1,
	]) );
	set("outdoors", "bat");
	set("coor/x",1010);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	//replace_program(ROOM);         
}


int valid_leave(object me, string dir)		//add by jusdoit at Dec 17,2001
{
	object ob;
	if( dir == "west" &&  me->query_temp("marks/gived_qfbook") ) {
		me->delete_temp("marks/gived_qfbook");
		return 1;
		}
	else
		return 1;
}