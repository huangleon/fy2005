inherit ROOM;
#include <ansi.h>

int refresh_skill(object xiaodie,object me);

void create()

{
        set("short", "����С��");
        set("long", @LONG
����С�Һܾ����������ʲôҲ�����룬Ҳ����Ҫ˵һ�仰��ֻҪ����������
����ֳ�Ĭ����Ȥ��һ���������������ܳ�Ĭ�����Ͳ������Ǹ�������˵�����ˣ�
��Ϊ�������˻�������ֻ����Щ�������Ĭ���˲���˵���������������ڰ���
��İ��£�ֻ��Ҫ��������������̸��
LONG
    );
        set("exits", ([ 
		"north": __DIR__"star_room1",
	]));
        
        set("objects", ([
		__DIR__"npc/xiaodie":	1,
	]) );
        
        set("item_desc", ([
    		
	]) );
	set("no_fly",1);
	set("no_fight",1);
        set("coor/x",-1690);
        set("coor/y",630);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

/*
void init() {
	object me;
	if( interactive(me = this_player())) {
		refresh_skill(this_object(),this_player());
	}
}


int refresh_skill(object xiaodie,object me) {
	
	string *my_skill,*x_skill;
	int i;
	
	
	xiaodie=present("xiao die",this_object());
	if (!xiaodie) {
		xiaodie=new(__DIR__"npc/xiaodie");
		xiaodie->move(this_object());
	}
		
	// delete all xiaodie's skills
	if (xiaodie->query_skills())
		x_skill = keys(xiaodie->query_skills());
	if (sizeof(x_skill)>0) {
		for (i=0;i<sizeof(x_skill);i++) {
			xiaodie->delete_skill(x_skill[i]);
//			tell_object(me,"С��������"+SKILL_D(x_skill[i])->name()+"��\n");
		}
	}
	xiaodie->delete("spouse");
	
	// setup xiaodie's skill according to guest's mark
	if (me->query("xiaodie")) {
		my_skill=keys(me->query("xiaodie"));
		if (sizeof(my_skill)>0) {
			for (i=0;i<sizeof(my_skill);i++)
				xiaodie->set_skill(my_skill[i],me->query("xiaodie/"+my_skill[i]));
		}
	}
	
	// set xiaodie's learn mark
	
	xiaodie->set("spouse",me);
	return 1;
}*/