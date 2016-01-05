// TIE@FY3
#include <ansi.h>
#include <login.h>
#define MAX_EXP 5000
inherit NPC;
string *death_msg = ({
	HIW "�й���������Ŀ����ѵ�һ����������ɨ��ɨȥ��\n\n"NOR,
	HIW "�йٷ��˷����겾��̾������һ��ز�۵Ķ�����\n\n"NOR,
	HIW "�йٺ��ϲ���˵��������δ�������˰��ˣ����߰ɡ�\n\n"NOR,
	HIW "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n"NOR,
});

string *revive_loc= ({
    	AREA_FY"church",
    	AREA_GUANWAI"tower",
});

void create()
{
    	set_name("����й�", ({ "panguan", "ghost judge" }) );
    	set("nickname", HIR"�����Ʊ������ж�"NOR);
    	set("long", "������ߵ�����й٣�ר���������˵�������\n");
    	set("attitude", "peaceful");
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	HIW"�йٺȵ���ţͷ��������ڣ�\n"NOR,
        	HIW "�й���������Ŀ����ѵ�һ����������ɨ��ɨȥ��\n\n"NOR,
        	HIW "�йٷ��˷����겾��̾������һ��ز�۵Ķ�����\n\n"NOR,
        	HIW "�йٺ��ϲ���˵��������δ�������˰��ˣ����߰ɡ�\n\n"NOR,
    	}) );
    	set("age", 217);
    	set("combat_exp", 20000000);
    	set("no_arrest", 1);
    	
    	setup();
    	carry_object("/obj/armor/ghost_cloth")->wear();
}

/*
void init()
{
    	::init();
    	if(!previous_object() || !userp(previous_object()) ){
        	return;
    	}
    	call_out( "death_stage", 3, previous_object(), 0 );
}


void death_stage(object ob, int stage){
	object cloth;
    	if( !ob || !present(ob)) return;
    	
    	
    	
	tell_object(ob, death_msg[stage]);
    	if( ++stage < sizeof(death_msg) ) {
        	call_out( "death_stage", 3, ob, stage );
        	return;
    	} else if (ob->is_ghost())
            	ob->reincarnate();
	cloth = new("/obj/armor/cloth");
	if(objectp(cloth)){
		cloth->move(ob);
		cloth->wear();
    	}
    	ob->move(revive_loc[random(sizeof(revive_loc))]);
    	ob->set("startroom", base_name(environment(ob)));
    	message("vision",
           		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
            		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}

*/


