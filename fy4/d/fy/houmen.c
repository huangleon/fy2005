// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ֺ�ɽ��");
        set("long", @LONG
���ֵĺ��ţ�����׳��ɮ�˰��ش˴�������ƽʱ������ֻ�е��е�
�Ӵ���ľ�����������ʱ�Ż�󿪺��ţ���ʾ��ף���������ȥ����
���ǽ�����һ��һ�ĸ����ˣ�

		��������Ӣ�ۣ�������˭��

LONG
        );
        set("exits", ([ 
  "south" : __DIR__"muma",
  "west" : AREA_SONGSHAN"talin",
]));
        set("objects", ([
                __DIR__"npc/monk2" : 6,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-630);
	set("coor/y",1230);
	set("coor/z",70);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="south" && ob=present("shaolin monk", this_object()))
return notify_fail( 
"����˵������λʩ�����������ţ�\n");
return 1;
}
void reset()
{
object *inv, ob;
string *sname=({"һ��","һ��","һ��","һ��",
"һ��","һ԰","һ��","һ��","һ��","һ��","һʮ"});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","һ��");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        {
	if(i<=3)
        ob->add_team_member(inv[i]);
        inv[i]->set("name",sname[i]);
        }
}
}

