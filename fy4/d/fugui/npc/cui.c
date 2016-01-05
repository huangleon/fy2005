#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "cuiming fu", "fu" }) );
        set("long",
         "������ɫ������ɫ�ģ����Ѻ������Ե�������Ϊһ�塣�������������\n��Ҳ�������ֻʣ����˫������۾����۾���û�й⣬Ҳ�ֲ����ڰף�\n��ȴ�����˶�֮�⡣\n");
        set("nickname", WHT "һ������"NOR);
        set("combat_exp", 1200000);

        set_temp("apply/damage",60);
        set("no_arrest",1);

        set_skill("unarmed", 150);
        set_skill("force",100);
        set_skill("parry",80);
        set_skill("dodge", 100);
        set_skill("move",100);
        set_skill("whip",150);
		set_skill("thunderwhip",120);
        set_skill("hawk-steps",150);
        set_skill("skyforce",100);
        set_skill("literate",100);
        set_skill("yunwu-strike",150);
        
        map_skill("unarmed","yunwu-strike");
        map_skill("whip","thunderwhip");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps");
        map_skill("force","skyforce");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "whip.tianleiyiji" :),
        }) );
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/ywhip")->wield();
}

void init()
{
	::init();
	add_action("do_get","get");
}


//  Ban : Get A from B

int do_get(string arg)
{
	object me, container;
	string *ban_location, *ban_item, arg1, arg2,what, where; 
	int num, i, ban;
					
	me=this_player();
	if(!arg) return notify_fail("������ʲô��\n");
	if (sscanf(arg,"%s from %s", what, where)!=2)		return 0;
	if (!objectp(container = present(where, environment(this_object()))))	return 0;

	if (base_name(container)!=AREA_FUGUI"obj/fentou")
		return 0;
	ban_item = ({ "ping", "ƿ" });				// well, you got to keep this right.
	
	if (what == "all")							ban = 1;
	if (member_array(what,ban_item)!=-1) 		ban = 1;
	if (present(what, container) && sscanf(what,"%s %d",arg2,num)==2)
		if (member_array(arg2,ban_item)!=-1) 	ban = 1;
	
	if (ban) {
		command("say ���ý�ҩ���ȹ�������һ����˵��");
		return 1;
	}
	
	return 0;

}		
