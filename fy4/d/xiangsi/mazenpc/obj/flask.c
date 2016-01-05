inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���ƿ", ({ "flask"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ӵ�ˮ��ƿ��\n");
		set("unit", "��");
		set("value", 2);
		set("max_liquid", 450);
	}

	set("liquid", ([
		"type": "water",
		"name": "����ɫ����ˮ",
		"remaining": 450,
		"drunk_apply": 7,
	]) );
	set("no_transfer",1);
	set("desc_ext","�ɷ��ڴ��������");
	set("generate_item",1);	// can be stack as boss item.

	::init_item();
}

void auto_fill()
{
	int i;
	if (query("liquid/name") != "����ɫ����ˮ")
		return;
	i = query("liquid/remaining");
	i += 30;
	if (i> 450)
		i=450;
	set("liquid/remaining",i);
	i /= 2;
	call_out("auto_fill",i);
}

void init()
{
  	if(this_player()==environment())
		auto_fill();
	::init();
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
