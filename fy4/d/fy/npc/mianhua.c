// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;
object ob;

void create()
{
	set_name("�ϰ���", ({ "clothes lady","lady" }) );
	set("title",HIR"�����޷�"NOR);
	set("gender", "Ů��" );
	set("age", 52);
	set("long",
		"�ϰ����ó����·������������·����ι̶��Ҳ��ѿ���\n");
	set("inquiry", ([
        	"ѩ��˿":	"���Ƿ���֮��������Ե�޷��õ���\n",
             	"�ڲ�˿":	"���Ƿ���֮��������Ե�޷��õ���\n",
             	"���˿":	"���Ƿ���֮��������Ե�޷��õ���\n",
   	]));
	
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_zhi","zhi");	
	add_action("do_xiu","bu");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "�ϰ���Ц������λ" + RANK_D->query_respect(ob)
				+ "�������������������Ҫ��һ���ˡ�\n");
			break;
		case 1:
			say( "�ϰ���˵������λ" + RANK_D->query_respect(ob)
				+ "��������������˿����ˣ�����һ�°ɡ�\n");
			break;
	}
}

int  do_zhi(string arg)
{
	object me;
	object gold;
	int cost = 1;
	int i,j,base,current, ji_times;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        
        if( !arg ) return notify_fail("��Ҫ֯ʲ�����\n");
        if(me->is_busy())
        	return notify_fail("����һ��������û����ɡ�\n");
        if( !objectp(ob = present(arg, me)) )
        	return notify_fail("������û������������\n");
        if( !ob->query("armor_prop") )
        	return notify_fail("��ֻ��֯�ܴ������ϵĶ�����\n");
        if( ob->query("equipped") )
        	return notify_fail("�㲻��֯�����ŵ����\n");
        if (ob->query("item_damaged"))
        	return notify_fail("����������ˣ����Ȱ������ò��С�\n");
        
                    
	base= (int)ob->query("base_armor");
	current = (int) ob->query("armor_prop/armor");
        
        if (base>50 && !me->query("ji_item/ѩ��˿"))
        	return notify_fail(CYN"�ϰ���˵�������"+ob->name()+CYN"��Ҫѩ��˿���ܽ�һ���ӹ̡���\n"NOR);
        if (base>80 && !me->query("ji_item/�ڲ�˿"))
        	return notify_fail(CYN"�ϰ���˵�������"+ob->name()+CYN"��Ҫ�ڲ�˿���ܽ�һ���ӹ̡���\n"NOR);
        if (base>120 && !me->query("ji_item/���˿"))
        	return notify_fail(CYN"�ϰ���˵�������"+ob->name()+CYN"��Ҫ���˿���ܽ�һ���ӹ̡���\n"NOR);
        
        if(!ob->query("ji_times")) {
		j = 1;
	} else {
		j = ob->query("ji_times");
	}
	if (j>=15) 
		return notify_fail("�ϰ���ҡ��ҡͷ˵����ƾ�ҵ��������Ѿ��޷��ټӹ���������ˣ���\n");
		
       	for(i=1; i<=j;i++)
		cost = cost * 2;
		tell_object(me, HIY"�ӹ����ｫ��ʹ��"+chinese_number(cost)+"���ƽ��Ƿ�Ҫ������(continue yes/no)\n"NOR);
        
        me->set_temp("process_zhi",ob);
        add_action("do_continue","continue");
        return 1;
}


int do_continue(string arg) {
	int i, j, cost = 1;
	object me = this_player();
	object ji_person;
	
	int gold = me->query("deposit")/10000;
	
	if (environment(me)!= environment(this_object())
		|| !me->query_temp("process_zhi")
		|| !objectp(me->query_temp("process_zhi"))
		)
		return notify_fail("ʲô����\n");
	
	
	if ( arg != "yes" ) { 
		write ("�ϰ���Ц�ݿ����˵����ӭ�´�������\n");
		me->delete_temp("process_zhi");
		remove_action("do_continue","continue");
		return 1; 
	}
	
	if( !objectp(ob = me->query_temp("process_zhi")) )
        	return notify_fail("������û������������\n");
        if( !ob->query("armor_prop") )
        	return notify_fail("��ֻ��֯�ܴ������ϵĶ�����\n");
        if( ob->query("equipped") )
        	return notify_fail("�㲻��֯�����ŵ����\n");
        if (ob->query("item_damaged"))
        	return notify_fail("����������ˣ����Ȱ������ò��С�\n");
        	
        me->delete_temp("process_zhi");		
	if(!ob->query("ji_times")) {
		j = 1;
	} else {
		j = ob->query("ji_times");
	}
	if (j>=15) 
		return notify_fail("�ϰ���ҡ��ҡͷ˵����ƾ�ҵ��������Ѿ��޷��ټӹ���������ˣ���\n");
		
	if (me->query_encumbrance()+j*50 > me->query_max_encumbrance())
		return notify_fail("����·��ټӹ���ȥ�����㴩�����ˡ�\n");
		
	for(i=1; i<=j;i++)
		cost = cost * 2;	

        if( gold < cost)
		{ 
	        	environment()->delete("processing");
	        	return	notify_fail("�����������" + sprintf("%d",cost)+ "�����ӡ�\n");
	       }
        
        me->add("deposit", -cost*10000);
        me->start_busy(1);
	me->save();
	seteuid(ROOT_UID);
	ob->unequip();
	ob->add("armor_prop/armor",j);
	ob->add("base_armor",j);
	ob->set("weight",(int)ob->query("weight")+j*50);
	ob->add("ji_times",1);
	ob->save();
	ob->restore();
	message_vision(CYN"$N�������ߣ���"+ob->name()+CYN"̯�����ϣ��ɿ��֯��������
һյ��Ĺ����ϰ��ﶶ�˶�"+ob->name()+CYN"��˵�������ˣ�\n"NOR,this_object());
	seteuid(getuid());
	remove_action("do_continue","continue");
	return 1;
}



int do_xiu(string arg){
	object gold, armor, me, reference;
	int dam, i, total;
	me = this_player();
	
	if(!arg) {
		return notify_fail("��Ҫ��ʲ�����\n");
	}
	
	armor = present(arg, me);
	if(!objectp(armor)) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	
	if(!armor->query("armor_prop")){
		return notify_fail("�ϰ���˵����ֻ�Ჹ��������Ŀɲ��ɡ�\n");
	}
	if(!armor->query("owner")) {
		seteuid(getuid());
		reference = new(base_name(armor));
		if (!reference) {
			message_vision("$N���˿�$n���е�" + armor->name() + "˵���������ֵ��һ����\n", 
				this_object(), me);
			return 1;
		}
		dam = reference->query("armor_prop/armor") - armor->query("armor_prop/armor");
		destruct(reference);
		
	} else {
	//	Self_made armor fix.	
		dam = armor->query("base_armor") - armor->query("armor_prop/armor");
    }
        
	if(dam <= 0) {
		return notify_fail("�������û���𻵡�\n");
	} 
	
	i = dam;
	
	total = MONEY_D->affordable(me,i*10000,1);	// Not allow credit card here
		
	if (!total)
		return notify_fail("������û���㹻�Ľ��ӣ���Ҫ����" + chinese_number(i) + "����\n");
	
	MONEY_D->pay_him(me,total-i*10000);
	
	if(armor->query("equipped") == "worn") {
		armor->unequip();
	}
	armor->add("armor_prop/armor", dam);
	armor->set("item_damaged",0);
	message_vision(CYN"$N�ӹ�$n���е�" + armor->name() + CYN"���ҿ����������ϲ���������\n"NOR, 
			this_object(), me);
 	message_vision(CYN"�����ˣ���$Nҧ��˿�ߣ��ֶ��˶����ݻ�" + armor->name() + CYN"��$n��\n"NOR,
 			this_object(), me);
 	tell_object(me,"������������ȥ�ƽ�"+chinese_number(i)+"����\n");
 	if (armor->query("orig_name"))
		armor->set("name",armor->query("orig_name"));
	if (armor->query("owner")) 
		armor->save();
	
	return 1;
}


int	accept_object(object who, object what) {
	
	string item_name;
	item_name= what->query("name");
	
	if (item_name=="ѩ��˿"|| item_name=="���˿"|| item_name=="�ڲ�˿"){
		who->set("ji_item/"+item_name,1);
		message_vision(CYN"�ϰ�������"+item_name+CYN"���˵�˵������ϡ��֮�����һ�����úñ��浽�ӹ����ߵ�ʱ��\n"NOR,who);
		return 1;
	}
	return 0;
}
		
	