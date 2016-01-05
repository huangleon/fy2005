#include <ansi.h>
inherit __DIR__"annieitem";

#define MAX_ITEM 9

void create()
{
	set_name("��ɫ�Ĵ�����", ({ "black case"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("prep","on");
	set("unit", "��");
	set("desc", "�����������������������ʹ��ָ��Ϊ��
Stack��	����Ʒ�����ɫ�Ĵ�����
	��������ʱ�쿴������Ʒ�ı��
Retrieve���Ӵ�������ȡ��ĳ��ŵ���Ʒ
Dispose�����Ӵ�����������ĳ��ŵ���Ʒ
\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","r");
	set("size",1);
	set("lore_item",1);
	set("value", 500000);
set("tax",10);
set("score_tax",10);
set("max_item",MAX_ITEM);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	{
		// add special action here.
        if (environment()->is_owner(this_player()->query("id"))) {
	        add_action("do_pawn", "stack");
	        add_action("do_expand","expand");
	        add_action("do_redeem1", "retrieve");
	        add_action("do_redeem2", "dispose");
		}
	}
}

int reset_item_list(object dest)
{
	return 1;
}

int do_expand(string arg){
	
	object env, item, me;
	string deco;
	me = this_player();
	
	if (!arg)
		return notify_fail("�����ʲô����?��\n");
		
	if (arg != "black tanmu")
		return notify_fail("��ֻ���üҾߵ���۵ĺ�̴ľ��\n");
	
	item = present(arg, me);
	if (!item)
		return notify_fail("������û�������Ʒ��\n");
		
	if (item->query("item_type")!= "xx")
		return notify_fail("��ֻ���üҾߵ���۵ĺ�̴ľ�����ݡ�\n");
	
	env = environment();
	
	if (query("extra_blackcase_size") >= 20)
		return notify_fail("��������Ѿ������������ˡ�\n");
	
	message_vision("$N����"+item->name()+"�����������ô���һ�󣬴�����ӱ�ø����ˡ�\n", me);
	
	environment()->add("extra_blackcase_size",5);
	environment()->save();
	destruct(item);
	return 1;
	
}

int do_pawn(string arg)
{
	string outstring="";
	object ob;
	string term,*terms, *vterms, *fterms;
	string data, p_c,capa;
	int value, pawn2_count=0, i,j, k, extra;
	int rvalue;
	mapping pawn2,vpawn2,fpawn2;
	object me;
	me = this_player();
	pawn2 = me->query_pawn2();
	vpawn2 = me->query_vpawn2();
	fpawn2 = me->query_fpawn2();

	if( !arg || !(ob = present(arg, this_player())) )
	{
	if( !mapp(pawn2) ||   !sizeof(pawn2) )
		write("\tû���κδ�ŵ���Ʒ��\n");
	else {
		terms = keys(pawn2);
		vterms = keys(vpawn2);	
		capa = "��"+ sizeof(terms)+"/"+ (environment()->query("extra_blackcase_size")+MAX_ITEM+1)+"��";	
			
			write( HIY"����������������������"NOR + HIR" Ŀǰ��ŵ���Ʒ"+ capa + NOR + HIY"����������������������\n"NOR
	     		+ HIY"����������������������"NOR + HIR"������������������������"NOR + HIY"����������������������\n"NOR);
                    
                for(i=0; i<sizeof(terms); i++) {
        			// Adjust spacing due to ANSI code
        			k = 0;
				extra = 0;
				for(j=0; j<strlen(pawn2[terms[i]]); j++) {
					if(pawn2[terms[i]][j] == ESC[0]) {
						k = 1;	
					}
					if(k == 1) {
						extra++;
					}
					if(pawn2[terms[i]][j] == 'm') {
						k = 0;	
					}
				}					      			
        			outstring =sprintf("%s%s\t%-5s��  %-*s  ��ֵ��%-25s%s\n", 
        					outstring, 
        					HIY"��"NOR,
        					terms[i], 
        					16+extra,
        					pawn2[terms[i]],
						MONEY_D->value_string(vpawn2[vterms[i]]),
						HIY"��"NOR);
        		}
        		this_player()->start_more("", outstring, 0);
        		write(HIY"��								  ��\n"NOR);
        		write(HIY"��"NOR "�쿴��stack�����루stack ��ƷӢ������				  "HIY"��\n"NOR);
        		write(HIY"��"NOR "ȡ����retrieve ��Ʒ��ţ��������٣�dispose ��Ʒ��ţ�		  "HIY"��\n"NOR);
        		write(HIY"��������������������"CYN"������������������������"HIY"������������������������\n"NOR);
              	
              }
	return 1;
	}


	if( !ob->query("generate_item") )
		return notify_fail("�㲻���Դ������������\n");
	if (ob->query("no_stack"))
		return notify_fail("�㲻���Դ������������\n");
	if (ob->query("no_drop"))
		return notify_fail("�㲻���Դ������������\n");
	
       if( mapp(pawn2) && sizeof(pawn2))
                {
                        terms = keys(pawn2);
			vterms = keys(vpawn2);
                        if(sizeof(vterms) > MAX_ITEM+environment()->query("extra_blackcase_size"))
                        return notify_fail("���Ѵ��̫����Ʒ�ˡ�\n");
                }
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܴ����Ʒ��\n");
// to make life more realistic
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	p_c = sprintf("%d",time()%10000);
	me->set_pawn2(p_c, term);
        me->set_vpawn2(p_c, 1);
        me->set_fpawn2(p_c, data);

	me->save();
	message_vision("$N�����ϵ�" + ob->query("name") + "�Ž���ɫ�Ĵ�������" + "��\n", this_player());

	ob->move(VOID_OB);
	destruct(ob);
	me->start_busy(1);
	return 1;
}




int do_redeem1(string arg)
{
        string num;
        int amount;
        string ob_file;
        object ob;
        int obnum;
        object me;
	string term, *terms;
	mapping pawn,vpawn,fpawn;

	object *inv;
	int i;

        int afford;
        if( !arg || sscanf(arg, "%s", num)!=1 )
                return notify_fail("ָ���ʽ��retrieve <��Ʒ���>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ�����ȡ��Ʒ��\n");
	pawn = me->query_pawn2();
	vpawn=me->query_vpawn2();
	fpawn=me->query_fpawn2();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("��û�е䵱�κ���Ʒ��\n");
	
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
	if( !amount )
			return notify_fail("�������Ʒ�����\n");
amount = amount * 3 /4;
	
	ob_file = fpawn[arg];
	ob = new(ob_file);

	inv=all_inventory(me);
			for(i=0;i<sizeof(inv);i++)
				if(ob->query("name")==inv[i]->query("name"))
					return notify_fail("�������������ֻ����һ����\n");

	if (ob->move(me)) {
	ob->set("no_drop",1);	
	ob->set("no_sell",1);	
	ob->set("no_stack",1);	
	ob->set("no_drop",1);

	me->save();
	message_vision("$Nȡ����һ��$n��\n", me, ob);
	return 1;
	}
	else  {
		destruct(ob);
		return notify_fail("�����ϵĶ���̫���ˡ���\n");
	}
	return 1;
}


int do_redeem2(string arg)
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
                return notify_fail("ָ���ʽ��dispose <��Ʒ���>\n");
        me = this_player();
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ�����������Ʒ��\n");
	pawn = me->query_pawn2();
	vpawn=me->query_vpawn2();
	fpawn=me->query_fpawn2();
	
	if (!mapp(pawn) || !mapp(fpawn) || !mapp(vpawn))
		return notify_fail("��û�е䵱�κ���Ʒ��\n");
		
	terms = keys(vpawn);
	amount = (int) vpawn[arg];
	if( !amount )
			return notify_fail("�������Ʒ�����\n");
amount = amount * 3 /4;
	
	ob_file = fpawn[arg];
     ob = new(ob_file);

			me->delete_pawn2(arg);
			me->delete_vpawn2(arg);
			me->delete_fpawn2(arg);

	me->save();
	message_vision("$N�����˴���ں�ɫ�Ĵ��������$n��\n", me, ob);
   	destruct(ob);
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
