// flowerowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Oct/29/2001

#include <ansi.h>
#include <dbase.h>

string *delivery_list = ({			// 10k - 20k
	"��Ѱ��:/d/quicksand/npc/bu_waiter:�����������Ų���",
	"½С��:/d/fy/npc/leng:�������������ķ���",
	"½С��:/d/fy/npc/fangyufei:�������������ķ���",
	"���ִ���:/d/fy/npc/bookgirl:���Ƴ��ڷ��Ƹ�¥��",
	"������:/d/jinan/npc/songtian:������ͻȪ",
	"������:/d/jinan/npc/surong:���ϴ�����",
	"����:/d/laowu/npc/alone:���ݰ���������",
	"���ִ���:/d/laowu/npc/dang:���ݲ����޹�С�Ƽ�",
	"��÷����:/d/laowu/npc/leng:���ݲ�ҩ��",
	"����:/d/chenxiang/npc/omonk:�����������",
	"�����:/d/chenxiang/npc/medman:���������ҩ��",
	"����:/d/guanwai/npc/waiter:���������ӭ÷��ջ",
	"С��:/d/guanwai/npc/sunshine:�����ԭ����֮��",
	"С��:/d/guanwai/npc/qi:������������ʯ��",		
	"������:/d/wudang/npc/dahanwife:�䵱ɽ����ũ��",
	"������:/d/wudang/npc/oldwoman:�䵱ɽ����ũ�ҳ���",
	
});

string *delivery_list_2 = ({			// 20k - 40k
	"���С��:/d/fugui/npc/tianxin:����ɽׯ��ʯ·����",
	"������:/d/fugui/npc/clothlady:����ɽׯ��ʯС�ָ���",
	"�����๫:/d/fugui/npc/beauty:����ɽׯɽ��С·����",
	"������:/d/huashan/npc/jin:��ɽ��ש��",
	"����:/d/huashan/npc/linger:��ɽ��Ժ",
	"������:/d/huashan/npc/gao:��ɽ������",
	"������:/d/baiyun/npc/fishwoman:�Ϻ�ɳ̲",
	"������:/d/baiyun/npc/niuroutang:�Ϻ�������",
	"������:/d/baiyun/npc/hockowner:�Ϻ����ǵ���",
	"������:/d/chuenyu/npc/cleangirl:����ɽ����",
	"������:/d/qingping/npc/laner:��ƽɽׯС��",
	"������:/d/qingping/npc/yan:��ƽɽׯ��԰",
	"������:/d/qianjin/npc/chick2:ǧ��¥",
	"������:/d/qianjin/npc/chick1:ǧ��¥",
	"������:/d/taoyuan/npc/singgirl:��Դ��С��ջ",
	"������:/d/taoyuan/npc/caier:��Դ�����",
	"������:/d/shenshui/npc/shui_tianji:����ľ����",
	"������:/d/taoguan/npc/watcher_taoist:����ɽ",
	"������:/d/taoguan/npc/jing2:����ɽ",
});

string *delivery_list_3 = ({		//40k - 60k
	"�����:/d/fy/npc/fangyuxiang:�������������ķ�������",
	"��ԭһ���:/d/guanyin/npc/qu:���ɽׯ��������",
	"չ�ΰ�:/d/palace/npc/feiyu:������ɽ�󸽽�",
	"����:/d/palace/npc/manfeng:�������鷿����",
	"��ʮһ��:/d/taishan/npc/shenbijun:̩ɽ̤ɯի",
	"������:/d/taishan/npc/lengqingshuang:̩ɽ�躺��",
	"��ʮһ��:/d/huangshan/npc/feng:��ɽ�ȹ��",
	"̫����:/d/huangshan/npc/yan:��ɽʯ���",
	"��ʮһ��:/d/huangshan/npc/bing:��ɽ�춼��",
	"������:/d/loulan/npc/bai:�ų�¥����ʯ��",
	"������:/d/loulan/npc/se:�ų�¥���Ϸ���",
	"������:/d/wolfmount/npc/xiaoling:��ɽ��佻�Ϫ",
	"������:/d/xiangsi/npc/suu:��˼���˪������",
	
});

string *delivery_list_4 = ({		//60k - 200k
	"½С��:/d/ghost/npc/yeling:����ɽׯ",
	"������:/d/eren/npc/pinggu:���˹�",
	"������:/d/eren/npc/xiaojiao:���˹�",
	"������:/d/zangbei/npc/gao:�ر���ԭ�Ŀ����",
	"������:/d/zangbei/npc/xiaodie2:�ر���ԭС����",
	"������:/d/zangbei/npc/dawa:�ر���ԭ������",
	"������:/d/zangbei/npc/girl:�߳Ǻ�̲",
	"������:/d/biancheng/npc/girl:�߳������",
	"������:/d/wolfmount/npc/yaomei:��ɽ������",
	"������:/d/tieflag/npc/maggirl:�����",
	"������:/d/tieflag/npc/shui:�����",
	"������:/d/cyan/npc/man:��ϼ��",
	"������:/d/cyan/npc/zhuxiang:��ϼ��",
	"������:/d/baiyun/npc/beautyboss:���Ƶ�",
	"������:/d/baiyun/npc/qianqian:���Ƶ�",
	"������:/d/baiyun/npc/mixian:���Ƶ�",
});

string *delivery_list_5 = ({		//500k - 650k
	"������:/d/qianjin/npc/funu:ǧ��¥",
	"������:/d/bat/npc/tong1:����",
	"�ձ���:/d/bat/npc/tong2:����",
	"��СС:/d/bat/npc/tong3:����",
	"������:/d/bat/npc/tong4:����",
	"������:/d/wolfmount/npc/yaomei:��ɽ������",
	"������:/d/shenshui/npc/needlegirl2:��ˮ��",
	"������:/d/shenshui/npc/qinggirl:��ˮ��",
	"������:/d/tieflag/npc/qinggirl2:������",
	"������:/d/tieflag/npc/qinggirl1:������",
	"������:/d/xiangsi/npc/seablue:��˼��",
	"������:/d/xiangsi/npc/leng2:��˼��",
	
});

string wait_period(int timep);

string get_flower()
{
	//get flower from the vendor list
	int i;
	mapping goods;
	string *names;
	if( !mapp(goods = query("vendor_goods")) ) 	return "";
	names = keys(goods);
	if (!sizeof(names))
	{
		//should we give out a default flower or don't let them deliver?
		return "";		// no more delivery
	}
	i = sizeof(names);
	return names[random(i)];
}

mapping query_delivery(object who)
{
	int i,exp;
	string *delivery,name;
	string *pick_list;
	object *ob,ob1;
	
	ob = users();
	
	ob1 = ob[random(sizeof(ob))];
	
	if (wizardp(ob1))	ob1 = ob[random(sizeof(ob))];
	if (wizardp(ob1))	ob1 = ob[random(sizeof(ob))];
	
	name = ob1->query("name");
	if (!name || wizardp(ob1))	name = "��Ѱ��";
		
	exp = who->query("combat_exp")/1000;
	if (exp<=20)	pick_list=delivery_list;
	else if (exp<=40)	pick_list = delivery_list_2;
	else if (exp<=60) 	pick_list = delivery_list_3;
	else if (exp<=200)	pick_list = delivery_list_4;
	else 				pick_list = delivery_list_5;
			
	i = sizeof(pick_list);
	delivery = explode(pick_list[random(i)],":");
	return (["sender": name,
			"receiver": delivery[1],
			"area":		delivery[2],
			]);
}

// CHecking Lists
void test_list(){

	string *pick;
	string *data;
	int i;
	object ob;
	
	pick = delivery_list_5;
	for (i=0;i<sizeof(pick);i++){
		data = explode(pick[i],":");
		if (objectp(ob=new(data[1]))){
			CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",ob) );
			destruct(ob);
		}	else
			CHANNEL_D->do_sys_channel("sys","error = "+ data[1]+"\n");
	}	
			
}

int assign_delivery()
{
	mapping delivery;
    	string dstr;
	object who,flower,silver;
    	who = this_player();
	
/*	if (who->query("combat_exp") >= 10000 )
	{
		message_vision("$N�ϻ̳Ͽֶ�$n��������ô��������ݡ���\n",this_object(),who );
		return 1;
	}
	
	if (who->query("KILLED") >= 20 )
	{
		message_vision("$N������һ���������"+RANK_D->query_respect(who)+"СС��ͣ���ôӡ�÷��ڣ���\n",this_object(),who );
		message_vision("$Nҡҡͷ˵�������������������ͻ������㲻�ʺϸɡ���\n",this_object());
		return 1;
	}*/
	
	 
	if(who->is_ghost() || who->is_zombie()) {
		tell_object(who,this_object()->name()+"�������Ҹò��Ǽ����˰ɣ���\n");
		return 1;
	}

	if((delivery =  who->query("delivery")) && (time() - who->query("delivery_time") <= 600)) {
		return 0;
	}
	
	//delivery unfinished and back to ask again in 10 mins
	if ((delivery =  who->query("delivery")) && (time() - who->query("delivery_time"))<= 1200)
	{
		tell_object(who,HIW"��Ҫ��" 
				+  QUESTS_D->wait_period(1200-time()+who->query("delivery_time")) 
				+ "֮��ſɼ����ͻ���\n"NOR);
		return 1;
	}
	//delivery cancled by player
	if ((!delivery =  who->query("delivery")) && ((who->query("next_delivery_time")) > time()))
	{
		tell_object(who,HIW"��Ҫ��" 
				+  QUESTS_D->wait_period(who->query("next_delivery_time") - time()) 
				+ "֮��ſɼ����ͻ���\n"NOR);
		return 1;
	}
/*
	silver=present("silver_money", who);
	if(!silver) 
	{
		tell_object(who,"������û���㹻�����Ӹ�����ѽ��\n");
		return 1;
	}
	if (silver->query_amount()<1)
	{
		tell_object(who,"������û���㹻�����Ӹ�����ѽ��\n");
		return 1;
	}
	silver->add_amount(-1);
*/

	if (who->query("deposit") < 100) {
		tell_object(who,"��������Ĵ���1�����ӡ�\n");
		return 1;
	}
	who->add("deposit",-100);
	
	delivery = query_delivery(who);
	flower = new(get_flower());
	if (!flower) {
		message_vision("$Nҡҡͷ˵��������Ļ����͹��ˡ���\n",this_object());
		return 1;
	}

	//flower->set("sender",delivery["sender"]);
	//flower->set("receiver",delivery["receiver"]);
	flower->set("delivery",delivery);
	flower->wither();
	if (flower->move(who))
	{
		who->set("delivery", delivery);
		flower->set("delivery_time", (int)time());	
		who->set("delivery_time", (int)time());	
		dstr = WHT"������" + delivery["sender"] + "�͸�ס��"+ delivery["area"]+"��"
+ delivery["receiver"]->name(1) + "�Ļ�������ȥ�ٻء���\n"NOR;
		message_vision("$NС������ݸ�$nһ��"+flower->name()+"����\n" + dstr,this_object(),who);

	} else
		destruct(flower);
	return 1;
}

int cancel_delivery(string arg)
{
	object who;
	who = this_player();
	if (arg != "delivery" && arg != "�ͻ�")
	{
		return 0;
	}
	if(  who->query("delivery") && (time() - who->query("delivery_time") < 600))
	{
		who->delete("delivery");
		who->delete("delivery_time");
		tell_object(who, this_object()->name() + "˵�����ðɣ�����ͻ���������˰ɣ���\n");
		who->set("next_delivery_time", time() + random(120));
		return 1;
	}else if (!who->query("delivery"))
	{
		return notify_fail("������û���κ��ͻ�����\n");
	}else
	{
		return notify_fail("���Ѵ����һ�����񡣵���һ���ɡ�\n");
	}
}

int give_deposit()
{
	int amount;
	object silver,me;
	me = this_player();
	amount = me->query("marks/delivery_success");
	if (amount>=1)
	{
/*		silver = new("/obj/money/silver");
		silver->set_amount(amount);
		message_vision("$N��$n�������������ȫ��Ѻ�𡣡�\n",this_object(),me);
		silver->move(me);*/
		
		me->add("deposit",100* amount);
		tell_object(me, this_object()->name()+"����˵�����Ѻ��"+amount+"�����ӣ��Ѿ�ȫ��ת����������˺��ˡ�\n");
		
		me->set("marks/delivery_success",0);
		return 1;
	}
	message_vision("$N��$n�������㲢û��Ѻ�����������\n",this_object(),me);
	return 1;

}

/*

the code which player place reservation
not in use right now
int book_flowers(string arg)
{
	string starget,sflower;
	object target,flower,who;
	mapping goods,userdelivery;
	string *names,flowerlist;
	who = this_player();
	flowerlist = "";
	if (!arg || sscanf(arg, "%s %s", starget,sflower) != 2 ) 
	{
		return notify_fail("�����ʽ:book ���ID ����ID\n");
	}	
	if (sizeof(user_reservation_list)>=20)
	{
		return notify_fail("���궩�����������ڽ����µĶ�����\n");
	}

	if (!target = find_player(starget))
	{
		return notify_fail("��ֻ��Ԥ������������ҡ�\n");
	}
	if( mapp(goods = query("vendor_goods")) ) 
	{
		names = keys(goods);
		if (sizeof(names)) 
		{
			for (int i=0;i<sizeof(names);i++ )
			{

				flowerlist = flowerlist + names[i]->name() + "("+names[i]->query("id")+")"+"\n";
				if ( names[i]->query("id") == sflower )
				{
					userdelivery = (["sender": who->name(1),
						"receiver": target->query("id"),
						"flower":names[i],
					]);
					user_reservation_list = user_reservation_list + ({userdelivery});
					message_vision("$NԤ����һ֧"+names[i]->name()+"��"+target->name(1)+"\n",who);
					return 1;
					
				}
			}
		}
	}

	if (flowerlist == "")
	{
		return notify_fail("����Ļ��������ˡ�\n");
	}
	tell_object(who,"������ֻ��Ԥ�����л���\n"+flowerlist);
	return 1;

}
*/
