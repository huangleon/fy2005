inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("�����", ({ "gaoliang skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ĸ����ƣ����ӻ���
ר���䵱ɽ�µĺ�����Ƴɣ��������ǡ�\n");
		set("unit", "��");
       	set("value", 20000);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
   		"name": "�����",
		"remaining": 15,
       	"drunk_apply": 30,
	]) );
	::init_item();
}
