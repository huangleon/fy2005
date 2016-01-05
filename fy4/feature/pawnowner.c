// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// Last Modified	- 02/16/2003 by silencer
// This file should be inherited by a pawnowner, who should have the following add_action
/* void init()
{
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
}
*/

#define MAX_PAWN 9
#include <dbase.h>
#include <ansi.h>

int do_value(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("��о��е㲻�Ծ���������Χ���˽����ض�ס���㡣\n");
	}
	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	value = ob->query("value");
	if( !value || value < 4) printf("%s����ֵ����Ǯ��\n", ob->query("name"));
	else 	{
		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), 
			MONEY_D->money_str(value),
			MONEY_D->money_str(value * 25 / 100), 
			MONEY_D->money_str(value * 80 / 100));
		if (ob->query("item_damaged"))
	       		tell_object(this_player(),"��������Ʒ�Ѿ����ˣ����޺�֮ǰ����û�˻����Ȥ�ġ�\n");
	}
	return 1;
}

int do_pawn(string arg)
{
	string outstring="";
	object ob;
	string term,*terms, *vterms, *fterms;
	string data, p_c,capa;
	int value, pawn_count=0, i,j, k, extra;
	int rvalue;
	mapping pawn,vpawn,fpawn;
	object me;
	me = this_player();
	pawn = me->query_pawn();
        vpawn = me->query_vpawn();
        fpawn = me->query_fpawn();

	if( !arg || !(ob = present(arg, this_player())) )
	{
	
	capa = "��"+ sizeof(vpawn)+"/"+ (this_player()->query("marks/pawn_expansion")+ MAX_PAWN+1)+"��";
		
	write( HIY"����������������������"NOR + HIR"��Ŀǰ�䵱��Ʒ"+capa+NOR + HIY" ����������������������\n"NOR
	     + HIY"����������������������"NOR + HIR"������������������������"NOR + HIY"����������������������\n"NOR);
//	write("��Ŀǰ�䵱����Ʒ�У�	������Ϊ��Ʒ��ֵ��75%��\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\tû���κε䵱����Ʒ��\n");
	else {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        for(i=0; i<sizeof(terms); i++) {
        			// Adjust spacing due to ANSI code
        			k = 0;
				extra = 0;
				for(j=0; j<strlen(pawn[terms[i]]); j++) {
					if(pawn[terms[i]][j] == ESC[0]) {
						k = 1;	
					}
					if(k == 1) {
						extra++;
					}
					if(pawn[terms[i]][j] == 'm') {
						k = 0;	
					}
				}					      			
        			outstring =sprintf("%s%s\t%-5s��  %-*s  ��ֵ��%-25s%s\n", 
        					outstring, 
        					HIY"��"NOR,
        					terms[i], 
        					16+extra,
        					pawn[terms[i]],
						MONEY_D->value_string(vpawn[vterms[i]]),
						HIY"��"NOR);
        		}
        		this_player()->start_more("", outstring, 0);
        		write(HIY"��								  ��\n"	
        			+"��������������������"CYN" ������Ϊ��Ʒ��ֵ��75%��"HIY"������������������������\n"NOR);
              }
	return 1;
	}
	
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("��о��е㲻�Ծ���������Χ���˽����ض�ס���㡣\n");
	}
	
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	if (ob->query("no_pawn"))
	{
		return notify_fail("�㲻���Ե�����������\n");
	}
	
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"˵�������겻�չ����˵Ķ�������\n");
	
	value = ob->query("value");
	if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
			vterms = keys(vpawn);
                        if(sizeof(vterms) > MAX_PAWN + this_player()->query("marks/pawn_expansion"))
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
                }
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܵ䵱��Ʒ��\n");
// to make life more realistic
	if( ((int)this_object()->query("richness")) < (value*25/100))
		return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
	this_object()->add("richness",-(value*25/100));
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	p_c = sprintf("%d",time()%10000);
	me->set_pawn(p_c, term);
        me->set_vpawn(p_c, value);
        me->set_fpawn(p_c, data);

	me->save();
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ MONEY_D->money_str(value * 25 / 100) + "��\n", this_player());

	MONEY_D->pay_player(this_player(), value * 25 / 100 );
	ob->move(VOID_OB);
	destruct(ob);
	me->start_busy(1);
	return 1;
}


int do_sell(string arg)
{
	object ob;
	int value,old, amount;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲ����Ʒ��\n");
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
	if (ob->query("thief_obj"))
	{
		call_out( (: call_other, MONEY_D, "arresthim", this_player() :), 3);
		this_player()->perform_busy(2);
		return notify_fail("��о��е㲻�Ծ���������Χ���˽����ض�ס���㡣\n");
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	value = ob->query("value");
        
        if (ob->query("no_sell")|| ob->query("no_drop")||ob->query("no_transfer"))
	       	return notify_fail("�㲻����������������\n");
	       	
        if( value<4)       	
        	 return notify_fail("������������ֵ�ܶ�Ǯ��\n");
	
	if (ob->query("item_damaged"))
		return notify_fail(this_object()->name()+"˵�������겻�չ����˵Ķ�������\n");
		
// to make life more realistic
        if( ((int)this_object()->query("richness")) < (value*80/100))
                return notify_fail(sprintf("%s����Ǯ�Ѿ������ˣ�����\n",this_object()->name()));
        this_object()->add("richness",-(value*80/100));

	if (this_player()->query_temp("timer/sale")+2 > time())
		return notify_fail(this_object()->name()+"��Ц�������͹��Ժ����Ͼ����к�����\n");
	this_player()->set_temp("timer/sale",time());

	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());
	old = this_object()->query_with_slash("vendor_goods."+base_name(ob));
// modified combined and throwing items. If the amount>base volumn, then calculate it and put
// in inventory, otherwise disgard it.	-- by Silencer 12/19/2002
	amount = ob->query("base_unit")? 
		 ob->query_amount()/ob->query_volumn():
		 1;
	if (amount)
		this_object()->set_with_slash("vendor_goods."+base_name(ob), old + amount);
	
	MONEY_D->pay_player(this_player(), value  * 80 / 100);
	ob->move(VOID_OB);
	destruct(ob);
//	this_player()->start_busy(1);	��timer����busy��ÿһ���ӽ���һ�Ρ�
	return 1;
}


int do_redeem(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
	string term, *terms;
	mapping pawn,vpawn,fpawn;
        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
	pawn = me->query_pawn();
	vpawn=me->query_vpawn();
	fpawn=me->query_fpawn();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("��û�е䵱�κ���Ʒ��\n");
		
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = MONEY_D->affordable(me, amount) ) {
			ob_file = fpawn[arg];
            ob = new(ob_file);

			// SOmetimes items are deleted
			if (!ob) {
				me->delete_pawn(arg);
				me->delete_vpawn(arg);
				me->delete_fpawn(arg);
				me->save();
				tell_object(me, "��Ϸ�䶯������Ʒ��ϵͳ���Ѿ��������ˣ��Զ�������¼��\n");
				return 1;
			}	

//                ob->set_amount(1);
// changed by karry 2002.5.13  �����������
            ob->query("base_unit")?((amount*100/75)/ob->query("base_value")<1?obnum=1:obnum=(amount*100/75)/ob->query("base_value")):obnum=1;
            ob->set_amount(obnum);
            if (ob->move(me)) {
				if (ob->query("no_transfer"))
				{
					ob->set("no_drop",1);	
				}	
				me->delete_pawn(arg);
	            me->delete_vpawn(arg);
	            me->delete_fpawn(arg);
		// to make life more realistic
		        this_object()->add("richness",amount);
		        	
		        	// CREDIT CARD
			    if (me->query("env/e_money")) {
					MONEY_D->charge_him(me,amount);
				} else
				{
					MONEY_D->pay_him(me, afford-amount);
				}
		        	
				me->save();
	            message_vision("$N�����$n��\n", me, ob);
	            return 1;
	        }
            else  {
               	destruct(ob);
               	return notify_fail("����û�취�������\n");
            }
                
        } else
            return notify_fail("���Ǯ������\n");
		me->start_busy(1);
}
