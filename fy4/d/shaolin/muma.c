// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ľ���");
        set("long", @LONG
����֣�û�뵽�ճ���ľ�����ֻ����������գ����Ȼվ��һ�����У����ܵ�
������ȫ��ľ�����㱼��������֮ѧ����Ȼ������˹���������ʱ�㿪����˵��
���֣�ֻ������Ҳ���ѱ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"houmen",
]));
        set("outdoors", "shaolin");
	set("no_magic",1);
	set("coor/x",0);
	set("coor/y",140);
	set("coor/z",20);
	setup();
}

void init()
{
        delete("exits");
        if(userp(this_player()))	{
        	remove_call_out("attack");
        	call_out("attack",1+random(2),this_player());
        }
}


int attack(object me)
{
	object muren;
	if (!me)	return 1;
		
	muren= new(__DIR__"npc/horse");
	muren->set("combat_exp",3000000 + 20000*random(100));
	muren->set_temp("apply/damage",500+50*random(10));
	muren->move(this_object());

	if (environment(me)==this_object())
		COMBAT_D->do_attack(muren,me);
	me->set_temp("last_damage_from","��������ľ����δ�죬��ľ�������ˡ�");
	
	if(present(me,this_object()) && random(9)){
		destruct(muren);
		call_out("attack",1+random(2),me);
	}
	else	{
		destruct(muren);
		set("exits/north", AREA_SONGSHAN"houmen");
		me->delete_temp("last_damage_from");
	}
	
}

