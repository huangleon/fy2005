// Tie@fy
#include <ansi.h>
#define GOLD_COST 500
#define SCORE_COST 200
inherit NPC;
void create()
{
        set_name("һ����Ӱ", ({ "shadowwoman" }) );
        set("gender", "Ů��" );
	set("title","��������");
        set("age", 332);
        set("long","���ۣ������Ǹ����ڿ��еĺ��ۣ�����\n");
        set("combat_exp", 3000000);
	set("max_force",10000);
	set("arrive_msg","���ɫ��Ũ���Ʈ�˹���������");
	set("leave_msg","�𽥰��������ˣ�����");	
	set("force",10000);
	set("force_factor",200);
	set("atman",1000);
	set("max_atman",1000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();

}

/*
void init()
{	
//        add_action("do_yaoye", "yaoye");
}

int do_yaoye(string arg)
{
	object me,ob,gold;
	int cost;
	string attr,what,prop;
        me = this_player();
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("ָ���ʽ��yaoye <name> <attribute>\n");
	if(sscanf(arg,"%s %s",what,attr) !=2)
	return notify_fail("ָ���ʽ��yaoye <name> <attribute>\n");
	ob = present(what,me);
	if(!objectp(ob)) return notify_fail("������û��"+what+"\n");
	if(!ob->query("max_enchant")  )
	return notify_fail(ob->name()+"�Ѿ�û�а취������ұ���ˣ�\n");
//okey we identified the target, now the cost:
        gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӡ�\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("������۲���"+chinese_number(SCORE_COST)+"�㡣\n");
	if(ob->query("equipped"))
	ob->unequip();
	if(ob->query("weapon_prop")) prop="weapon_prop/";
	else prop="armor_prop/";
	switch (attr){
	case "����" :
	case "caizhi" :
			ob->add(prop+"intelligence",1);
			break;
        case "����" :
        case "tizhi" :
			ob->add(prop+"constitution",1);
                        break;
        case "����" :
        case "lingxing" :
                        ob->add(prop+"spirituality",1);
                        break;
        case "����" :
        case "meili" :
                        ob->add(prop+"personality",1);
                        break;
        case "����" :
        case "yongqi" :
                        ob->add(prop+"courage",1);
                        break;
        case "����" :
        case "liliang" :
                        ob->add(prop+"strength",1);
                        break;
        case "����" :
        case "naili" :
                        ob->add(prop+"durability",1);
                        break;
        case "����" :
        case "renxing" :
			ob->add(prop+"flexibility",1);
                        break;
        case "�ٶ�" :
        case "sudu" :
                        ob->add(prop+"agility",1);
                        break;
        case "����" :
        case "qiliang" :
                        ob->add(prop+"tolerance",1);
                        break;
        case "����" :
        case "yunqi" :
                        ob->add(prop+"karma",1);
                        break;
        case "����" :
        case "dingli" :
                        ob->add(prop+"composure",1);
                        break;
        default :
			return notify_fail("û�а취��"+attr+"����ұ����"+ob->name()+"\n");

	}
	ob->add("max_enchant",-1);
	ob->save();
	gold->add_amount(-GOLD_COST);
	me->add("score",-SCORE_COST);
	message_vision("$N��$n΢΢���˵�ͷ������\n",this_object(),me);
	return 1;
}

void unconcious()
{
	int gin,kee,sen;
	gin =(int)query("max_gin");
	kee =(int)query("max_kee");
	sen =(int)query("max_sen");
	set("eff_kee",kee);set("kee",kee);
	set("eff_gin",gin);set("gin",gin);
	set("eff_sen",sen);set("sen",sen);
	return ;

}

void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

*/