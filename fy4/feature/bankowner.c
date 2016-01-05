//bankowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/16/2001 by Daniel Q. Yu.
//		- 02/16/2003 by silencer

// This file should be inherited by a banker, who should set add_action of following fuctions.
/*void init()
{
        ::init();
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
}
*/


#include <ansi.h>
#define MAX_CARRY 29

int do_convert(string arg) {
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
       
        // check for busy status. 
	if(this_player()->is_busy()) {
		return notify_fail("��Ķ�����û����ɣ����ܶһ�Ǯ��\n");
	}
	
	// check from args.
	if(!arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3) {
		return notify_fail("ָ���ʽ��convert <����> <��������> to <��������>\n");
	}
	if(amount < 1) {
		return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");
	}
	
	// check for from money type.	
	from_ob = present(from + "_money", this_player());
	if(!from_ob) {
		return notify_fail("������û�����ֻ��ҡ�\n");
	}
	if((int)from_ob->query_amount() < amount) {
		return notify_fail("������û�������" + from_ob->query("name") + "��\n");
	}
	bv1 = from_ob->query("base_value");
	if(!bv1) {
		return notify_fail("���ֶ�����ֵǮ��\n");
	}
	
	// check for to money type
	if(!objectp(to_ob = present(to + "_money", this_player())) && !objectp(to_ob = load_object("/obj/money/" + to + ".c"))) {
		return notify_fail("����һ���һ��Ǯ��\n");
	}
	bv2 = to_ob->query("base_value");
	if(bv1 < bv2) amount -= amount % (bv2 / bv1);
	if(amount==0) {
		return notify_fail("��Щ" + from_ob->query("name") + "�ļ�ֵ̫���ˣ�������\n");
	}
	
	if (bv1==bv2)
		return notify_fail("ͬ���Ļ��ң���ʲô�ɻ��ģ�\n");
	
	this_player()->start_busy(1);
	
	// exchange the money.
	to_ob = new("/obj/money/" + to);
	to_ob->set_amount(amount * bv1 / bv2);
	if (to_ob->move(this_player())) {
		message_vision(sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
			chinese_number(amount), 
			from_ob->query("base_unit"), 
			from_ob->query("name"),
			chinese_number(amount * bv1 / bv2), 
			to_ob->query("base_unit"), 
        	 	to_ob->query("name")),
			this_player());
		from_ob->add_amount(-amount);
	}
	else {
		destruct(to_ob);
		return notify_fail("�һ�û�гɹ���\n");
	}
	
	return 1;
}

int do_deposit(string arg) {
	int bv,amount;
	int damount;
	string type;
	object type_ob;
 
 	// check for busy status
 	if(this_player()->is_busy()) {
		return notify_fail("��Ķ�����û����ɣ����ܴ�Ǯ��\n");
	}
	
	// check for command args
	if(!arg || sscanf(arg, "%d %s", amount, type)!=2 ) {
		return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	}
	if(amount <= 0) {
		return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
	}

	// check for desposite.
	type_ob = present(type + "_money", this_player());
	if(!type_ob) {
		return notify_fail("������û�����ֻ��ҡ�\n");
	}
	if((int)type_ob->query_amount() < amount) {
		return notify_fail("������û�������" + type_ob->query("name") + "��\n");
	}
	bv = type_ob->query("base_value");
	if(!bv) {
		return notify_fail("���ֶ�����ֵǮ��\n");
	}
	
	damount = (int)this_player()->query("deposit");
	damount += amount * bv;
	// to make life more realistic
	this_object()->add("richness",amount * bv);
	this_player()->set("deposit", damount);
	message_vision(sprintf("$N������%s%s%s��\n", chinese_number(amount), 
			type_ob->query("base_unit"), type_ob->query("name")), this_player());
	type_ob->add_amount(-amount);
	this_player()->save();
	this_player()->start_busy(1);
	
	if (amount*bv >=10000)	// ����¼�������ϵİɣ���ֹ�������� flooding
	log_file("BANKING_LOG", sprintf("%s,%s(%s)������%d�ġ�\n",
		ctime(time()), this_player()->name(1),this_player()->query("id"), amount*bv));
	
	return 1;
}

int do_balance(string arg) {
	int value;
	value= (int) this_player()->query("deposit");
        if(value == 0){
        	tell_object(this_player(),"������û�д�\n");
		return 1;
	}
	if(value > 0) 
		tell_object(this_player(),"�����ڹ��д�\n");
	else {
		tell_object(this_player(),HIR"�����ڹ�Ƿ�\n"NOR);
		value = -value;
	}
        
        tell_object(this_player(), HIY"		"+ MONEY_D->money_str(value) + "\n"NOR);
	return 1;
}


int do_withdraw(string arg)
{
	int amount;
	int hamount;
	object *inv;
	
    if( this_player()->is_busy() )
    	return notify_fail("����һ��������û����ɣ�����ȡǮ��\n");
    if( !arg || sscanf(arg, "%d", amount)!=1 )
    	return notify_fail("ָ���ʽ��withdraw <����> \n");
	hamount = (int) this_player()->query("deposit");
	if(amount <=0 )
		return notify_fail("ָ���ʽ��withdraw <����> \n");
	if(amount>hamount) 
		return notify_fail("��û��ô���� ����\n");
 // to make life more realistic
    if( ((int)this_object()->query("richness")) < amount)
        return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
        
    inv = all_inventory(this_player());
	if(sizeof(inv) >= MAX_CARRY) 
		return notify_fail("�������Ѿ�����̫�ණ���ˣ��޷���ȡǮ��\n");
			
    this_object()->add("richness",-amount);
	hamount -= amount;
	this_player()->set("deposit", hamount);
	MONEY_D->pay_player(this_player(), amount,1);
	tell_object(this_player(), "��ȡ����" +MONEY_D->money_str(amount)+ "��\n");
	this_player()->save();
	this_player()->start_busy(1);
	
	// ����¼�������ϵİɣ���ֹ�������� flooding
	if (amount>=10000)
		log_file("BANKING_LOG", sprintf("%s,%s(%s)ȡ����%d�ġ�\n",
			ctime(time()), this_player()->name(1),this_player()->query("id"), amount));
	
	return 1;

}


int do_loan(string arg)
{
	int amount;
	int hamount;
	if( (int)this_player()->query("mud_age") < 3600)
		return notify_fail("��ո�̤����ƣ����ܽ�Ǯ��\n");
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɣ����ܽ�Ǯ��\n");
	
	return notify_fail("�������к�̨��ɽ�����ˣ�Я��Ǳ�ӣ��Ѿ��޷����������ˡ�\n");
		
	if( sscanf(arg, "%d", amount)!=1 )
		return notify_fail("ָ���ʽ��loan <����> \n");
	
	hamount = (int) this_player()->query("deposit");
	if(hamount > 0 ) return notify_fail("�㻹�д�\n");
    	if(amount <=0)
               return notify_fail("ָ���ʽ��loan <����> \n");
	if((int)this_player()->query("combat_exp") < amount - hamount)
			return notify_fail("��費����ô��Ǯ������\n");
	//seems no need this check, well, it doesn't hurt, leave it now
	if( hamount - amount > hamount)
			return notify_fail("��費����ô��Ǯ������\n");
 // to make life more realistic
        if( ((int)this_object()->query("richness")) < amount)
                return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
    
    this_object()->add("richness",-amount);
    this_player()->set("deposit", hamount - amount);
    MONEY_D->pay_player(this_player(), amount,1);
        tell_object(this_player(), "�ϣ� \n");
	this_player()->save();
	this_player()->start_busy(1);
        return 1;

}

int do_transfer(string arg) {
	string to;
	int amount, hamount;
	object to_player;
       
    	// check for busy status. 
	if(this_player()->is_busy()) {
		return notify_fail("��Ķ�����û����ɣ�����ת�ʡ�\n");
	}
	
	// check from args.
	if(!arg || sscanf(arg, "%d to %s", amount,to)!=2) {
		return notify_fail("ָ���ʽ��transfer <����> to <���ID>\n");
	}
	if(amount <=0 )
		return notify_fail("ָ���ʽ��transfer <������> to <���ID>\n");
	
	hamount = (int) this_player()->query("deposit");
	if(amount>hamount) 
		return notify_fail("��û��ô���� ����\n");
	if (!to_player = find_player(to))
	{
		return notify_fail("��ֻ��ת�ʸ�������ҡ�\n");
	}
	hamount -=amount;
	this_player()->set("deposit", hamount);
	hamount = (int) to_player->query("deposit");
	hamount += amount;
	to_player->set("deposit", hamount);
//	tell_object(this_player(),"��ת��"+(string)amount+"��Ǯ��"+to_player->name()+"\n");
	tell_object(this_player(),WHT"��ת��  "+ MONEY_D->money_str(amount)+"��"+to_player->name()+"��\n"NOR);
	tell_object(to_player, WHT""+this_player()->name()+"ת��  "+ MONEY_D->money_str(amount) + "���㡣\n"NOR);
	this_player()->save();
	this_player()->start_busy(1);
	
		// ����¼�������ϵİɣ���ֹ�������� flooding
	if (amount>=10000)
		log_file("BANKING_LOG", sprintf("%s,%s(%s)��%d��ת����%s(%s)��\n",
			ctime(time()), 
			this_player()->name(1),this_player()->query("id"),
			amount,
			to_player->name(1), to_player->query("id")));
		
	return 1;
}
