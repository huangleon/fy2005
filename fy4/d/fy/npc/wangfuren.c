// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;
inherit F_LEVEL;
object ob;

void create()
{
        set_name("������", ({ "fan furen","fan","furen" }) );
        set("gender", "����" );
        set("title", HIR "����ʦ"NOR);
        set("age", 52);
        set("long","�����˱������幬��һ���ϵ�ʿ���˵������������£�
��������˼�����\n");

        set("inquiry",([
                "��Ԩڤ��" :"��Ԩڤ��ԭ���ǵظ���������˵�ڰ�����ǰ�����˼䣬����֮���ؾ�������\n",
                "��ڤ�Ͼ�" :"��ڤ�Ͼ���ϡ��֮������˵ֻ�дϻ۾���֮�˲��ܵõ���\n",
                "�ϻ۾���":	"����������Ǹ�����ƭ������ķ��ڷ����ǻ���롣\n",
              ]) );

        set("combat_exp", 50000);
        set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
        add_action("do_ji","ji");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob) && REWARD_D->riddle_check(ob,"��ڤ�Ͼ�")==1) 
        {
			message_vision(CYN"
����������͸�����еĹ⣬������ڤ���齣���૵�˵���������ǧ���������ڤ�Ͼ�
���ɵİ�����ϧұ��֮�˲����䷨�������˵ظ�֮�䡣ֻҪ���ҵ���Ԩڤ�������԰ٽ�
���ң��ҾͿ�����ұ�˽�����Ϊ��ڤ�Ͼ���\n"NOR, this_object()); 
        } else {
            switch( random(10) ) {
                    case 0:
                            say( "������Ц������λ" + RANK_D->query_respect(ob)
                                    + "����ı��п���������ҪѪ��һ���ˡ�\n");
                            break;
                    case 1:
                            say( "������˵������λ" + RANK_D->query_respect(ob)
                                    + "����ı���ɱ�����㣬��Ѫ��һ�±��аɡ�\n");
                            break;
                    case 2: message_vision("���������������˵���Ǵ���֮����ڤ�Ͼ���Ҳ��֪�����䵽�����\n",ob);
                    		break;
            }
        }
}


int accept_object(object who, object ob) {
        object sword;
        string item_name, ob_name;
        string *material_names=({ "��ڤ���齣",MAG"��Ԩڤ��"NOR });
        int success, makeup_ok, i;
        if (query("busy"))
        	return notify_fail("������������æ��\n");
        	
        item_name= ob->query("real");
        if (item_name=="��β�Ͳ�"|| item_name=="��������"|| item_name=="ǧ���ϲ�"){
                who->set("ji_item/"+item_name,1);
                message_vision(CYN"����������"+item_name+CYN"���˰��Σ�ϲ����ɫ��\n�����˸����°���ϡϡ�����ļ������ӣ��ٺ�Ц������������\n"NOR,who);
                return 1;
        }

		if (ob->query("money_id") == "gold") {
     		if (REWARD_D->riddle_check(who,"��ڤ�Ͼ�")!=2) {
     			command("shake");
     			command("say �ȵ������ڤ���齣�Ͳ�Ԩڤ�����Ҹ�����˵�ɡ�");
     			return 0;
     		}
            if (ob->query_amount() < 100 ) {
                command("shake");
                command("say ����Ǽ����¶���û��������ò�������");
                return 0;
            }            
            
            message_vision("\n$N��$n�ó���ڤ���齣������ұ��¯�С�\n", this_object(), who); 
            message_vision(HIC"¯�𽥽��Ӻ�ɫת�����֮ɫ���������ͳ���Ԩڤ��Ͷ�˽�ȥ��
���һ����¯���ִ���һ�߶�ߡ�����������\n"NOR, this_object());
            set("busy", 1);
            call_out("ext_stone", 3, who);
            who->perform_busy(2);
            return 1;
		}
		
		ob_name=ob->query("name");
		
		if (REWARD_D->riddle_check(who,"��ڤ�Ͼ�")!=1) {
			if (ob_name ==MAG"��Ԩڤ��"NOR)
				command("say �㻹����ȥ�ҵ���ڤ���齣�ɡ�");
				return 0;
		}			
		
		success=1;
		makeup_ok=0;
		for(i=0;i<2;i++)
		{
			if(ob_name==material_names[i])
			{
				if(who->query("marks/wangfuren/"+ob_name))
				{
					command("say ��ԭ�����Ѿ��������ˣ���\n");
					return 0;
				}
				if (ob_name==MAG"��Ԩڤ��"NOR && !who->query("annie/ب�Ż��"))
				{
					ccommand("say ��Ԩڤ��Ψ���Լ����ֵõ��Ĳ�����������");
					return 0;
				}
				who->set("marks/wangfuren/"+ob_name,1);
				command("say �ã������������¡�");
				makeup_ok=1;
			}
			success = success*who->query("marks/wangfuren/"+material_names[i]);
		}
		if(!success) return makeup_ok; 

		command("say �ã�ԭ�϶��Ѿ����ˣ�ֻҪ���㹻���ʽ��Ҿ��ܹ�����ڤ�Ͼ���ȡ������");
		REWARD_D->riddle_set(who,"��ڤ�Ͼ�",2);
		return 1;				

        
}

//	You can keep the stone, but if you lose it, you still have the mark
//	YOu can either ask other to get the stone, or do it youself again.
int ext_stone(object me){
        object stone;
        set("busy", 0);
        if (!me)	return 1;
        if (environment(me) == environment(this_object())) {
            message_vision(MAG"\n��Ȼ�䣬�Ϲ���ҫ��ӳ����ء�\n"NOR, this_object()); 
            message_vision(HIR"$N��Ȼ�õ����Լ����ֱ���һ����һ��Ѫ������ұ��¯��\n"NOR, this_object()); 
            message_vision(MAG"\n�Ϲ��ʢ֮�£��㲻�ɵñ����۾���\n"NOR, this_object());
            message_vision("���ۿ�ʱ���������ѽ�һ���Ĺ���������ʯ�������С�\n", this_object()); 
            
            stone = new("/obj/specials/stone/pstone");
            if (stone->move(me)) {
            	message_vision("$N�ݸ�$nһ����ʯ��\n", this_object(), me);
            	REWARD_D->riddle_done(me,"��ڤ�Ͼ�",200,1);
	        	if(!me->query("stone_mark/pstone")){
	            	me->set("stone_mark/pstone",1);
	            }
	            log_file("riddle/IMBUE_LOG",
                  sprintf("%s(%s) ������ڤ�Ͼ��ɹ��� %s \n",
                        me->name(1), geteuid(me), ctime(time()) ));
        	}else
        		stone->move(this_object());
        } 
        return 1;
}

object get_material(object me)
{
	object *inv;
	int i;
	inv=all_inventory(me);
	for (i=0;i<sizeof(inv); i++)
		if (inv[i]->query("weapon_material"))
			return inv[i];
	return 0;
}

int  do_ji(string arg)
{
        object me,obx;
        
        int gold;
        int cost =1;
        int i,j,base,current;
        string id,name,broken;  
        string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("��Ҫ��ʲ��������\n");

		if (me->query("created_item")>1)
			return notify_fail("������ҡͷ��������ֻ����һ�������������뽫�������destroy�������١�\n");
		
		
		obx=get_material(me);
		if (!obx)
			return notify_fail("������ҡͷ�����������ǿɵ��кò��ϲ��С�\n");

		if (me->query("ji/"+obx->query("material_level")))
			return notify_fail("������ҡͷ�������Ѿ���"+obx->name()+"�����ˡ�\n");

//      gold = present("gold_money", this_player());
//      if( !gold) return notify_fail("������û�н��ӡ�\n");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");
        if(me->is_busy())
                return notify_fail("����һ��������û����ɡ�\n");
        if( !ob->query("weapon_prop") )
                return notify_fail("��ֻ�ܼ��ɵ��������Ķ�����\n");
        if( ob->query("equipped") )
                return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("owner") )
                return notify_fail("��ֻ�ɼ��Լ������������\n");
        
        sscanf(ob->query("name"),"%s��",broken);
        if(broken=="�ϵ�")
                return notify_fail("�㲻�ɼ����˵���������ȥ�����������޺�������������\n");
        
        base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage");
        if (base != current)
                return notify_fail("�㲻�ɼ����˵���������ȥ�����������޺�������������\n");

/*
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }

        if (j>=15) 
                return notify_fail("������ҡ��ҡͷ˵����ƾ�ҵ��������Ѿ��޷��ټ���������ˣ���\n");
        else if (j >= 12 && !me->query("ji_item/��β�Ͳ�"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧��β�Ͳ������ϵ�ʿ��һ����\n\n");
        else if (j >= 10 && !me->query("ji_item/��������"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧�������������ϵ�ʿ��һ����\n\n");
        else if (j >= 8 && !me->query("ji_item/ǧ���ϲ�"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧ǧ���ϲ������ϵ�ʿ��һ����\n\n");

        for(i=1; i<=j;i++)
                cost = cost * 2;
*/
		cost = 10;
        tell_object(me, HIY"����������ʹ��"+chinese_number(cost)+"���ƽ��Ƿ�Ҫ������(continue yes/no)\n"NOR);
        add_action("do_continue","continue");
        me->set_temp("process_ji",ob);
        return 1;
}

int do_continue(string arg) {
        int i, j, cost = 1;
        object me = this_player();
        object ji_person,obx;
        string broken;
        int gold, base, current;
                
        if (environment(me)!= environment(this_object())
                || !me->query_temp("process_ji")
                || !objectp(me->query_temp("process_ji"))
                )
                return notify_fail("ʲô��\n");
                
                
        if ( arg != "yes" ) { 
                write ("������Ц�ݿ����˵����ӭ�´�������\n");
                me->delete_temp("process_ji");
                remove_action("do_continue","continue");
                return 1; 
        }

		obx=get_material(me);
		if (!obx)
			return notify_fail("������ҡͷ�����������ǿɵ��кò��ϲ��С�\n");

		if (me->query("ji/"+obx->query("material_level")))
			return notify_fail("������ҡͷ�������Ѿ���"+obx->name()+"�����ˡ�\n");

		if (exp_to_level(me->query("combat_exp"))["level"]<obx->query("material_level"))
			return notify_fail("������ҡͷ���������ﵽ"+obx->query("material_level")+"�������ô���Ʒ������\n");
        
        if( !objectp(ob = me->query_temp("process_ji")) )
                return notify_fail("������û������������\n");
        
        me->delete_temp("process_ji");
        
        if( !ob->query("weapon_prop") )
                return notify_fail("��ֻ�ܼ��ɵ��������Ķ�����\n");
        if( ob->query("equipped") )
                return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("owner") )
                return notify_fail("��ֻ�ɼ��Լ������������\n");
        
        sscanf(ob->query("name"),"%s��",broken);
        if(broken =="�ϵ�")
                return notify_fail("�㲻�ɼ����˵���������ȥ�����������޺�������������\n");
        
        base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage");
        if (base != current)
                return notify_fail("�㲻�ɼ����˵���������ȥ�����������޺�������������\n");
/*
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }




        if (j>=15) 
                return notify_fail("������ҡ��ҡͷ˵����ƾ�ҵ��������Ѿ��޷��ټ���������ˣ���\n");
        else if (j >= 12 && !me->query("ji_item/��β�Ͳ�"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧��β�Ͳ������ϵ�ʿ��һ����\n\n");
        else if (j >= 10 && !me->query("ji_item/��������"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧�������������ϵ�ʿ��һ����\n\n");
        else if (j >= 8 && !me->query("ji_item/ǧ���ϲ�"))
                return notify_fail("������ҡҡͷ�����ϵ�ʿ���ʧѪ̫�࣬�����ѽ������ǡ������ǡ���\n������ͻȻ�����ۣ��ٺ�Ц������������֧ǧ���ϲ������ϵ�ʿ��һ����\n\n");
*/
        if (me->query_encumbrance()+j*100 > me->query_max_encumbrance())
                return notify_fail("��������ټ���ȥ�������ò����ˡ�\n");
        
		cost = 10;

        gold = me->query("deposit")/10000;
        if( gold < cost)
                return  notify_fail("�����������" + sprintf("%d",cost)+ "�����ӡ�\n");
        
        me->start_busy(1);        
        me->add("deposit", -cost*10000);
        me->add("bellicosity",cost);
        
// need to update 3 things: damage, rigidity, and weight, base_damage is to keep track
// damage on weapon so we can xiu weapon later on.
        seteuid(ROOT_UID);

		me->add("ji/"+obx->query("material_level"),1);

        ob->unequip();
        ob->add("weapon_prop/damage",10);
        ob->add("base_damage", 10);
        ob->set("weight",ob->query("weight")+300);
        ob->add("rigidity",50);
        ob->add("ji_times", 1);
        ob->save();
        ob->restore();
        me->save();
        seteuid(getuid());
        
        message_vision("\n$N��$n����ȡ��"+ob->name()+"��"+obx->name()+"������ұ��¯�С�\n", this_object(), me); 
        message_vision(HIC"¯�𽥽��Ӻ�ɫת�����֮ɫ��\n\n\n"NOR, this_object());
        message_vision(HIR"$N��Ȼ�õ����Լ����ֱ���һ����һ��Ѫ������ұ��¯��\n"NOR, this_object()); 
        message_vision(HIC"\n¯����֮�£��㲻�ɵñ����۾���\n"NOR, this_object());
        message_vision("$N˵�������ˣ�\n\n",this_object());
        message_vision("���ۿ�ʱ���������ѽ�$n������$N���С�\n", me, ob); 
                
		destruct(obx);
        remove_action("do_continue","continue");
        return 1;
}

