// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���۱���");
        set("long", @LONG
�˵��г������̨����̨������һӦ��ȫ�����ڹ�������������������Ĳ
��𣬰����ӷ��ҩʦ����Ϊ������������ǰ����������δ�������ܱڻ�Χ�ƣ�
���죬������ӵ���棬��������������ƣ����˲��ɵ�������η�������������Ҷ
���飺
		
			���۱���

LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"dianjiao",
  "eastdown" : __DIR__"jinna",
  "westdown" : __DIR__"liuzu",
  "northdown" : __DIR__"yonglu2",
]));
        set("objects", ([
                __DIR__"npc/master_22" : 1,
       ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
        if( userp(me))
        if( dir == "northdown" && ob=present("master yuan", this_object()))
	if((int)me->query("combat_exp") < 10000)	
	{
	ob->ccommand("shake");
	return notify_fail("");
	}
return 1;
}
