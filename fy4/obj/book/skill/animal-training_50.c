inherit ITEM;

void create()
{
	set_name("ѵ����", ({ "book", "animal-training book"}));
	set_weight(600);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    	set("unit", "��");
	    	set("long",  "����һ������ѵ�������顣\n");
	    	set("value", 100);
	    	set("no_transfer",1);
		set("material", "paper");
	    	set("skill", ([
	            	"name": "animal-training",
	            	"exp_required": 100000,
	            	"sen_cost": 10,
	            	"difficulty": 35,
	            	"max_skill": 50,
	    	]) );
	}
}