// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ֺ�ɽ��");
        set("long", @LONG
���ֵĺ��ţ�����׳��ɮ�˰��ش˴�������ƽʱ������ֻ�е��е��Ӵ���ľ��
���������ʱ�Ż�󿪺��ţ���ʾ��ף���������ȥ������ǽ�����һ��һ�ĸ�
���ˣ�

		��������Ӣ�ۣ�������˭��

LONG
        );
        set("exits", ([ 
		
  		"west" : AREA_SONGSHAN"talin",
  		"in":	AREA_MAZE"sl-entry",
	]));
        set("objects", ([
                __DIR__"npc/monk21" : 1,
                __DIR__"npc/monk22" : 1,
                __DIR__"npc/monk23" : 1,
                __DIR__"npc/monk24" : 1,
                __DIR__"npc/monk25" : 1,
                __DIR__"npc/monk26" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",67);
	set("coor/y",25);
	set("coor/z",0);
	setup();
}

/*
void reset()
{
	object *inv, ob;
	string *sname=({"һ��","һ��","һ��","һ��",
	"һ��","һ԰","һ��","һ��","һ��","һ��","һʮ"});
	int i,j;
	::reset();
	j=1;
	ob=present("shaolin monk", this_object());
	if(ob) ob->set("name","һ��");
//	if(ob) ob->set("chat_chance_combat",10);
	
	inv = all_inventory();
	if(ob)
	{
	ob->dismiss_team();
	for(i=0;i<sizeof(inv);i++)
	        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
	        {
			if(j<=3) ob->add_team_member(inv[i]);
		        inv[i]->set("name",sname[j]);
		        j++;
	        }
	}
}

*/