// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʨ�ӷ�");
        set("long", @LONG
�˴�Զ������һͷ��ʨ��ͷ��β��������ǰ������ʤ��������ʨ���֣����룬
���������ɣ����ţ���˵ȹŰض��Ǻ������������������С�û��ʨ�ӷ壬������
ɽ�١���ʢ������������̨��Ϊ���������������˱�ȥ֮����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qingliang",
  "east" : __DIR__"sanhua",
]));
        set("objects", ([
        __DIR__"npc/su" : 1,
	__DIR__"npc/su2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",30);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="west" && (ob=present("bai hong", this_object())
|| ob=present("bai huan", this_object())) && me->query("bellicosity")>50)
return notify_fail(
ob->name()+"˵������������\n");
return 1;
}
void reset()
{
object me,me2;
:: reset();
me2=present("bai huan",this_object());
me=present("bai hong",this_object());
if(me) me->dismiss_team();
if(me2) me2->dismiss_team();
if(me && me2) me->add_team_member(me2);
}
