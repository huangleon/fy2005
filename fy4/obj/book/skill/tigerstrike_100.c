inherit ITEM;

void create()
{
        set_name("ɽ��", ({ "ɽ��","hill", "shanluan" }));  
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("unit", "");
		set("long","
ɽ���绢���۰�һ����������צ���������ˣ��鶯���ѣ��ý����ף�
�ƺ�����һ�Ÿ�����书��\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
        	set("skill", ([
                	"name":        "tigerstrike", 
                	"exp_required": 0,                  
                	"sen_cost":     15,         
                	"difficulty":   30,                 
                	"max_skill":    99,                  
        	]) );
 	}
 	
 }
 
 