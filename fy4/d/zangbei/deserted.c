#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����һƬ��ԫ�ϱڣ����䶫�������С���ݣ�û���ţ�û�д���ֻ��һ����
�Ŀ������紵�����ص��졣������һ������Ľ��죬��ȥ�Ƴ�����ϡ���Ա������
�ſ�ջ�������֣�����ԭ�ǹ�������Ъ��֮������֪Ϊʲô�������ˡ�
LONG
        );
        set("exits", ([ 
	  	"southwest" : __DIR__"qingtongxia",
			]));
	
		set("item_desc", ([
			"����" : "������ƺ���·�����������תת����\n",
		]));
	set("objects", ([
		__DIR__"npc/bandit2" : 2,
	]));
	set("outdoors", "zangbei");

        set("coor/x",-450);
	set("coor/y",600);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init() {
	
	 add_action("do_around", "around");
}

int do_around(){
	object me, room;
	object bandit;
	
	me=this_player();
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
	if (present("bandit") && me->query("combat_exp")<2500000) {
		tell_object(me,"����˵��Ϲתתʲôת���޹�����ү����һ��ת��\n");
		return 1;
	}
			
	if (present("bandit") && me->query("combat_exp")>2500000) 
		tell_object(me,"���������㣬�����������붯ȴû�Ҷ���\n");
		
		
	tell_object(me,YEL"\n���ڷ���������ϸϸת�˼������أ���ǰ��Ȼһ����\n\n"NOR);
	room = find_object(__DIR__"banditcamp1");
    if(!objectp(room)) 
      	room = load_object(__DIR__"banditcamp1");
    me->move(room); 
	message("vision",me->query("name")+"��������ȥ�����˼�Ȧ�����ˡ�\n",this_object());
	return 1;
}


