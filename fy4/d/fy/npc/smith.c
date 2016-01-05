#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);
int get_ji_times(object me);

void create()
{
	set_name("������", ({ "smith zhang","smith","zhang" }));
	set("title", HIR"���Ƶ�һ��"NOR);
	set("gender", "����");
	set("age", 52);
	set("long", "������һ��������������鴫��������������������á�\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob=this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_ding", "ding");
	add_action("do_xiu", "xiu");
	add_action("do_estimate","estimate");
	add_action("do_rebuild", "rebuild");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) {
		return;
	}
	switch( random(5) ) {
		case 0:
			say( "����������������˵������λ" + RANK_D->query_respect(ob) + "��Ҫʲô��\n");
			break;
		case 1:
			say( "������������ˮ˵������λ" + RANK_D->query_respect(ob) + "����̫æ�ˣ��ﲻ���㡣\n");
			break;
	}
}

int do_estimate(string arg)
{
	object me, weapon, reference;
	int dam, total;

	me = this_player();
	if( !arg ) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	weapon = present(arg, me);
	if( !objectp(weapon) ) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if( !weapon->query("weapon_prop") ) {
		return notify_fail("������˵����ֻ���ޱ����������Ŀɲ��ɡ�\n");
	}
	if( !weapon->query("owner") ) {
		// ͨ����������
		seteuid(getuid());
		reference = new(base_name(weapon));
		if( !reference ) {
			message_vision("$N���˿�$n���е�" + weapon->name() + "˵���������ֵ��һ�ޡ�\n", this_object(), me);
			return 1;
		}
		// �е�����õ���clone��Ʒ����������û���ޡ�
		if( reference->query("name") != weapon->query("name") ) {
			message_vision("$N���˿�$n���е�" + weapon->name() + "˵���������û��ԭͼ�������޲��á�\n", this_object(), me);
			return 1;
		}
		dam = reference->query("weapon_prop/damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0 ) {
			return notify_fail("�������û���𻵡�\n");
		} else if( reference->query("weapon_prop/damage") < 25 ) {
			total = 1; // �����һ��Quest�õĶ�����1 gold per fix��
		} else {
			total = dam *3;	//�����������������,�ٺٲ�������һ����ܡ�
		}
		destruct(reference);
	} else {
		// ������������
		dam = weapon->query("base_damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0) {
			return notify_fail("�������û���𻵡�\n");
		} else {
			total = dam;	// 1 gold per damage fix for self-made weapon.
		}
		// ɱ����=150��������಻����base_damage/4
		if( total > weapon->query("base_damage")/4 ) {
			total = weapon->query("base_damage")/4;
		}
	}
	tell_object(me,"������˵������˰ѱ�����Ҫ�ƽ�"+ chinese_number(total) + "�������ȷ��������xiuָ�\n");
	return 1;
}

int do_xiu(string arg) {
	object me, weapon, reference;
	int dam, i, total;

	me = this_player();
	if( !arg ) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	weapon = present(arg, me);
	if( !objectp(weapon) ) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if( !weapon->query("weapon_prop") ) {
		return notify_fail("������˵����ֻ���ޱ����������Ŀɲ��ɡ�\n");
	}
	if( !weapon->query("owner") ) {
		// ͨ����������
		seteuid(getuid());
		reference = new(base_name(weapon));
		if( !reference ) {
			message_vision("$N���˿�$n���е�" + weapon->name() + "˵���������ֵ��һ�ޡ�\n", this_object(), me);
			return 1;
		}
		// �е�����õ���clone��Ʒ����������û���ޡ�
		if( reference->query("name") != weapon->query("name") ) {
			message_vision("$N���˿�$n���е�" + weapon->name() + "˵���������û��ԭͼ�������޲��á�\n", this_object(), me);
			return 1;
		}
		dam = reference->query("weapon_prop/damage") - weapon->query("weapon_prop/damage");
		if( dam <= 0) {
			return notify_fail("�������û���𻵡�\n");
		} else if( reference->query("weapon_prop/damage") < 25)	{
			i = 1; // �����һ��Quest�õĶ�����1 gold per fix��
		} else {
			i = dam *3; // �����������������,�ٺٲ�������һ����ܡ�
		}
		destruct(reference);
	} else {
		// ������������
		dam = weapon->query("base_damage") - weapon->query("weapon_prop/damage");
		if(dam <= 0) {
			return notify_fail("�������û���𻵡�\n");
		} else {
			i = dam;	// 1 gold per damage fix for self-made weapon.
		}
		// ɱ����=150��������಻����base_damage/4
		if( i > weapon->query("base_damage")/4 ) {
			i = weapon->query("base_damage")/4;
		}
	}
	if( !me->query("env/e_money") ) {
		total = MONEY_D->affordable(me, i*10000, 1);
		if(!total) {
			return notify_fail("������û���㹻�Ľ��ӣ���Ҫ����" + chinese_number(i) + "����\n");
		}
		MONEY_D->pay_him(me, total-i*10000);
	} else {
		if( me->query("deposit") < i*10000) {
			return notify_fail("��������û���㹻�Ľ��ӣ���Ҫ����" + chinese_number(i) + "����\n");
		}
		me->add("deposit",-i*10000);
	}
	if( weapon->query("equipped") == "wielded" ) {
		weapon->unequip();
	}
	weapon->add("weapon_prop/damage", dam);
	weapon->set("item_damaged", 0);
	message_vision("$N�ӹ�$n���е�" + weapon->name() + "�ô����ô��˼��¡�\n", this_object(), me);
	message_vision("�����ˣ���$N�ݻ�" + weapon->name() + "��$n��\n", this_object(), me);
	tell_object(me,"������������ȥ�ƽ�"+chinese_number(i)+"����\n");
	if( weapon->query("orig_name") ) {
		weapon->set("name", weapon->query("orig_name"));
	}
	if( weapon->query("owner") ) {
		weapon->save();
	}
	return 1;
}


int do_ding(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me;
	string id, newfile,filename,timestamp;
	int total;

	me = this_player();
	id = me->query("id");

	if( !arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4 ) {
		return notify_fail("ָ���ʽ��ding <type> <color> <name> <English name>\n");
	}
	if( me->is_busy() ) {
		return notify_fail("����һ��������û����ɡ�\n");
	}
	if( me->query("combat_exp") < 50000 ) {
		return notify_fail("������Ʒ������Ҫ����ȼ�Ϊ�塣\n");
	}
	if( (int)me->query("created_item") > 0 ) {
		return notify_fail("�����ֻ��ӵ��һ��������Ʒ��\n");
	}

	total = MONEY_D->affordable(me, 100000, 1);
	if( !total ) {
		return notify_fail("������û��ʮ�����ӡ�\n");
	}
	if( sizeof(all_inventory(me)) >= 14 ) {
		return notify_fail("�����ϵĶ���̫���ˣ��Ҵ��˱�����Ҳû���á�\n");
	}
	if( !check_legal_name(cname) ) {
		return notify_fail("");
	}
	if( !check_legal_id(cid) ) {
		return notify_fail("");
	}

	if( ccolor != "$BLK$" &&
		ccolor != "$NOR$" &&
		ccolor != "$RED$" &&
		ccolor != "$GRN$" &&
		ccolor != "$YEL$" &&
		ccolor != "$BLU$" &&
		ccolor != "$MAG$" &&
		ccolor != "$CYN$" &&
		ccolor != "$WHT$" &&
		ccolor != "$NOR$" &&
		ccolor != "$HIR$" &&
		ccolor != "$HIG$" &&
		ccolor != "$HIY$" &&
		ccolor != "$HIB$" &&
		ccolor != "$HIM$" &&
		ccolor != "$HIC$" &&
		ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	ccolor = replace_string(ccolor, "$BLK$", "BLK");
	ccolor = replace_string(ccolor, "$RED$", "RED");
	ccolor = replace_string(ccolor, "$GRN$", "GRN");
	ccolor = replace_string(ccolor, "$YEL$", "YEL");
	ccolor = replace_string(ccolor, "$BLU$", "BLU");
	ccolor = replace_string(ccolor, "$MAG$", "MAG");
	ccolor = replace_string(ccolor, "$CYN$", "CYN");
	ccolor = replace_string(ccolor, "$WHT$", "WHT");
	ccolor = replace_string(ccolor, "$HIR$", "HIR");
	ccolor = replace_string(ccolor, "$HIG$", "HIG");
	ccolor = replace_string(ccolor, "$HIY$", "HIY");
	ccolor = replace_string(ccolor, "$HIB$", "HIB");
	ccolor = replace_string(ccolor, "$HIM$", "HIM");
	ccolor = replace_string(ccolor, "$HIC$", "HIC");
	ccolor = replace_string(ccolor, "$HIW$", "HIW");
	ccolor = replace_string(ccolor, "$NOR$", "NOR");
	seteuid(ROOT_UID);
	switch( ctype ) {
		case "axe":
			newfile = read_file("/obj/selfmake/weapons/axe.o");
			break;
		case "blade":
			newfile = read_file("/obj/selfmake/weapons/blade.o");
			break;
	/*	case "dagger":
			newfile = read_file("/obj/selfmake/weapons/dagger.o");
			break;
		case "fork":
			newfile = read_file("/obj/selfmake/weapons/fork.o");
			break;*/
		case "hammer":
			newfile = read_file("/obj/selfmake/weapons/hammer.o");
			break;
		case "staff":
			newfile = read_file("/obj/selfmake/weapons/staff.o");
			break;
		case "sword":
			newfile = read_file("/obj/selfmake/weapons/sword.o");
			break;
		case "whip":
			newfile = read_file("/obj/selfmake/weapons/whip.o");
			break;
		case "spear":
			newfile = read_file("/obj/selfmake/weapons/spear.o");
			break;
	/*	case "banzhi":
			newfile = read_file("/obj/selfmake/weapons/fist.o");
			break;*/
		default:
			return notify_fail("���ﲻ������Ҫ�Ķ�����\n");
	}
	timestamp = sprintf("%c%c%c%c%c%c%c", 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20));
	newfile = replace_string( newfile, "������", cname);
	newfile = replace_string( newfile, "order", cid);
	newfile = replace_string( newfile, "fengyun", id);
	newfile = replace_string( newfile, "COR", ccolor);
	newfile = replace_string( newfile, "STAMP", timestamp);
	filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +timestamp + ".c";

	if( !write_file(filename, newfile,1) ) {
		return 0;
	}
	ob = new(filename);
	ob->set("weight", 3000);
	ob->set("rigidity", 50);
	ob->set("weapon_prop/damage", 10);
	ob->set("base_damage", 10);
	ob->set("enhance_time", 0);
	ob->set("orig_name", ob->query("name"));
	ob->save();
	ob->restore();
	if( ob->move(me) ) {
		MONEY_D->pay_him(me, total-100000);
		me->add("created_item", 1);
		me->start_busy(1);
		write("���������ͷ�������ץ��һ����ͭ������ԭ�ߣ������һ"+ob->query("unit")+ ob->name()+"\n");
		message_vision(YEL"$N�ݸ���$nһ" + ob->query("unit") + ob->name() + YEL"����̾��һ�������������ı������������Եģ�\n"NOR, this_object(), me);
		message_vision(YEL"Ҳ��֪���������м������ܹ����ס���\n"NOR, this_object());
		seteuid(getuid());
		return 1;
	} else {
		destruct(ob);
		tell_object(me,WHT"�����������������뾡��֪ͨ��ʦ��\n"NOR);
	}
	return 0;
}

int do_rebuild(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me;
	string id, newfile, filename, timestamp;
	int ji_times;

	me = this_player();
	id = me->query("id");

	if( !arg || sscanf(arg,"%s %s %s %s",ctype, ccolor, cname, cid) != 4 ) {
		return notify_fail("ָ���ʽ��rebuild <type> <color> <name> <English name>\n");
	}

	if( me->is_busy() ) {
		return notify_fail("����һ��������û����ɡ�\n");
	}

	if( me->query("combat_exp") < 50000 ) {
		return notify_fail("������Ʒ������Ҫ����ȼ�Ϊ�塣\n");
	}

	if( (int)me->query("created_item") <= 0 ) {
		return notify_fail("��û�д����������Ʒ����ô�ָ���\n");
	}

	if( (int)me->query("rebuilt_item") > 0 ) {
		return notify_fail("��ֻ�ָܻ�һ��������Ʒ��\n");
	}

	if( sizeof(all_inventory(me)) >= 14 ) {
		return notify_fail("�����ϵĶ���̫���ˣ��Ҵ��˱�����Ҳû���á�\n");
	}

	if( !check_legal_name(cname) ) {
		return notify_fail("");
	}

	if( !check_legal_id(cid) ) {
		return notify_fail("");
	}

	if( ccolor != "$BLK$" && 
		ccolor != "$NOR$" &&
		ccolor != "$RED$" &&
		ccolor != "$GRN$" &&
		ccolor != "$YEL$" &&
		ccolor != "$BLU$" &&
		ccolor != "$MAG$" &&
		ccolor != "$CYN$" &&
		ccolor != "$WHT$" &&
		ccolor != "$NOR$" &&
		ccolor != "$HIR$" &&
		ccolor != "$HIG$" &&
		ccolor != "$HIY$" &&
		ccolor != "$HIB$" &&
		ccolor != "$HIM$" &&
		ccolor != "$HIC$" &&
		ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	ccolor = replace_string(ccolor, "$BLK$", "BLK");
	ccolor = replace_string(ccolor, "$RED$", "RED");
	ccolor = replace_string(ccolor, "$GRN$", "GRN");
	ccolor = replace_string(ccolor, "$YEL$", "YEL");
	ccolor = replace_string(ccolor, "$BLU$", "BLU");
	ccolor = replace_string(ccolor, "$MAG$", "MAG");
	ccolor = replace_string(ccolor, "$CYN$", "CYN");
	ccolor = replace_string(ccolor, "$WHT$", "WHT");
	ccolor = replace_string(ccolor, "$HIR$", "HIR");
	ccolor = replace_string(ccolor, "$HIG$", "HIG");
	ccolor = replace_string(ccolor, "$HIY$", "HIY");
	ccolor = replace_string(ccolor, "$HIB$", "HIB");
	ccolor = replace_string(ccolor, "$HIM$", "HIM");
	ccolor = replace_string(ccolor, "$HIC$", "HIC");
	ccolor = replace_string(ccolor, "$HIW$", "HIW");
	ccolor = replace_string(ccolor, "$NOR$", "NOR");
	seteuid(ROOT_UID);
	switch( ctype ) {
			case "axe":
					newfile = read_file("/obj/selfmake/weapons/axe.o");
					break;
			case "blade":
					newfile = read_file("/obj/selfmake/weapons/blade.o");
					break;
/*			case "dagger":
					newfile = read_file("/obj/selfmake/weapons/dagger.o");
					break;
			case "fork":
					newfile = read_file("/obj/selfmake/weapons/fork.o");
					break;*/
			case "hammer":
					newfile = read_file("/obj/selfmake/weapons/hammer.o");
					break;
			case "staff":
					newfile = read_file("/obj/selfmake/weapons/staff.o");
					break;
			case "sword":
					newfile = read_file("/obj/selfmake/weapons/sword.o");
					break;
			case "whip":
					newfile = read_file("/obj/selfmake/weapons/whip.o");
					break;
			case "spear":
					newfile = read_file("/obj/selfmake/weapons/spear.o");
					break;
/*			case "banzhi":
					newfile = read_file("/obj/selfmake/weapons/fist.o");
					break;*/
			default:
				return notify_fail("���ﲻ������Ҫ�Ķ�����\n");
	}
	timestamp = sprintf("%c%c%c%c%c%c%c", 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20), 'a'+random(20));
	newfile = replace_string( newfile, "������", cname);
	newfile = replace_string( newfile, "order", cid);
	newfile = replace_string( newfile, "fengyun", id);
	newfile = replace_string( newfile, "COR", ccolor);
	newfile = replace_string( newfile, "STAMP", timestamp);
	filename = DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + id + timestamp + ".c";

	if( !write_file(filename, newfile,1) ) {
		return 0;
	}

	ob = new(filename);
	ob->set("weight", 3000);
	ob->set("rigidity", 50);
	ob->set("weapon_prop/damage", 10);
	ob->set("base_damage", 10);
	ob->set("enhance_time", 0);
	ob->set("orig_name", ob->query("name"));

	ji_times = (int)get_ji_times(me);
	ob->add("weapon_prop/damage", 10*ji_times);
	ob->add("base_damage", 10*ji_times);
	ob->set("weight", ob->query("weight") + 300*ji_times);
	ob->add("rigidity", 50*ji_times);
	ob->save();
	ob->restore();
	if( ob->move(me) ) {
		me->add("rebuilt_item", 1);
		me->start_busy(1);
		write("���������ͷ�������ץ��һ����ͭ������ԭ�ߣ������һ"+ob->query("unit")+ ob->name()+"\n");
		message_vision(YEL"$N�ݸ���$nһ" + ob->query("unit") + ob->name() + YEL"����̾��һ�������������ı������������Եģ�\n"NOR, this_object(), me);
		message_vision(YEL"Ҳ��֪���������м������ܹ����ס���\n"NOR, this_object());
		seteuid(getuid());
		return 1;
	} else {
		destruct(ob);
		tell_object(me, WHT"�����������������뾡��֪ͨ��ʦ��\n"NOR);
	}
	return 0;
}


int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
		write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ����������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ������ֱ��������ġ�\n");
			return 0;
		}
	}
	return 1;
}


int check_legal_id(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
		write("�Բ���Ӣ�����ֱ�����������ʮ���֡�\n");
		return 0;
	}
	return 1;
}

int get_ji_times(object me)
{
	int ntimes = 0;
	if( me->query("ji/" + "12") ) {
		ntimes++;
	}
	if( me->query("ji/" + "19") ) {
		ntimes++;
	}
	if( me->query("ji/" + "26") ) {
		ntimes++;
	}
	if( me->query("ji/" + "33") ) {
		ntimes++;
	}
	if( me->query("ji/" + "40") ) {
		ntimes++;
	}
	if( me->query("ji/" + "47") ) {
		ntimes++;
	}
	if( me->query("ji/" + "54") ) {
		ntimes++;
	}
	if( me->query("ji/" + "61") ) {
		ntimes++;
	}
	if( me->query("ji/" + "68") ) {
		ntimes++;
	}
	if( me->query("ji/" + "80") ) {
		ntimes++;
	}
	if( me->query("ji/" + "90") ) {
		ntimes++;
	}
	if( me->query("ji/" + "110") ) {
		ntimes++;
	}
	if( me->query("ji/" + "120") ) {
		ntimes++;
	}
	if( me->query("ji/" + "130") ) {
		ntimes++;
	}
	if( me->query("ji/" + "135") ) {
		ntimes++;
	}
	ntimes += (int)me->query("ji2_times");
	return ntimes;
}