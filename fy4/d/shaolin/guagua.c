// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Ӵ��");
        set("long", @LONG
����ΪͬԴ����������׼����ס����������������ͥ�������������ذ�ɽ����
�߲����������صرٳ��˵أ����η�����ʹ�ã����ڳ���򵥣�һ��ͨ�̼�����ÿ
������һ��С������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"neiyuan",
  "east" : __DIR__"yibo",
]));
        set("objects", ([
                __DIR__"npc/other_monk1" : 1,
                __DIR__"npc/other_monk2" : 1,
                __DIR__"npc/other_monk3" : 1,
                __DIR__"npc/other_monk4" : 1,
                __DIR__"npc/other_monk5" : 1,
                __DIR__"npc/other_monk6" : 1,
                __DIR__"npc/other_monk7" : 1,
                __DIR__"npc/other_monk8" : 1,
                
       ]) );
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

/*
void reset()
{
object *inv, ob;
string *sname = ({"ɽ���µĺ���","�˹����µĺ���","����ĺ���","ӡ�ȵĺ���","��ɽ�µĺ���","�����µĺ���","��ɽ�ĺ���","̩��ĺ���"});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","ɽ���µĺ���");
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++){
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        inv[i]->set("name",sname[i]);
	}
}
}
*/                                           
